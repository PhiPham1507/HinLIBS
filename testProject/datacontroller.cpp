 #include "datacontroller.h"
#include "patron.h"
#include "item.h"
#include <QtSql/qsqlquery.h>
#include <iostream>

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

DataController::DataController() : patronAcc(nullptr), libAcc(nullptr){
    itemSize = data.itemSize();
}

void DataController::setPatron(Patron *patron){
    patronAcc = patron;
}
void DataController::setLibrarian(Librarian *lib){
    libAcc = lib;
}

void DataController::displayItems(){
    for(int i = 0; i < itemSize; i++){
        cout << data.getItem(i)->display();
    }
}
void DataController::removeItem(int index){
    data.removeItem(index);
}
vector<Item*> DataController::getItems()
{
    /*
    vector<Item*> items;
    for (int i = 0; i < itemSize; ++i)
    {
        items.push_back(data.getItem(i));
    }
*/
    return data.getItems();
}

bool DataController::getItemAvailability(int id)
{
    Item* item = data.findItem(id);
    if(item == nullptr) return false;
    return item->getAvailability();
}

Item* DataController::getItemById(int id)
{
    return data.findItem(id);
}


Account* DataController::authenticate(const string &user, const string &pass){

    Account* findAcc = data.findUser(user);
    if(findAcc == nullptr) return nullptr;
    if(findAcc->getPassword() == pass){
        return findAcc;
    }else{
        return nullptr;
    }

}

void DataController::accLoggedOut(){
    patronAcc = nullptr;
    libAcc = nullptr;
}

/*
bool DataController::checkOut(int id){
    Item* item = data.findItem(id);
    if(item == nullptr) return false;
    if(!item->getAvailability()) return false;
    bool patronCO = patronAcc->checkOut(item);
    if(!patronCO) return false;
    item->setAvailability(false);
    return true;
}
*/

bool DataController::checkOut(int id) {
    Item* item = data.findItem(id);
    if (!item) return false;

    Account* acc = getCurrentAccount();
    Patron* patron = dynamic_cast<Patron*>(acc);
    if (!patron) return false;

    // If item is currently marked unavailable, bail out
    if (!item->getAvailability()) return false;

    // ==== HOLDS RULE ====
    Patron* head = item->getNextInQueue();

    if (head != nullptr) {
        // There IS a queue; only the first in line can check out
        if (head != patron) {
            // Not your turn → cannot check out even though 'available' is 1
            return false;
        }

        // It IS this patron's turn:
        //  - remove their hold in memory
        //  - remove from item's queue
        patron->removeHold(item);
        item->popNextInQueue();

        //  - remove their hold in DB
        QSqlQuery delHold;
        delHold.prepare("DELETE FROM Holds WHERE user_id = ? AND item_id = ?");
        delHold.addBindValue(QVariant(patron->getDbId()));
        delHold.addBindValue(QVariant(item->getId()));
        if (!delHold.exec()) {
            qDebug() << "Failed to delete hold for patron on checkout:"
                     << delHold.lastError().text();
        }

        //  - renumber remaining positions for this item
        data.renumberHoldsForItem(item->getId());
    }

    // ==== NORMAL CHECKOUT LOGIC ====
    if (!patron->checkOut(item)) return false;
    item->setAvailability(false);

    QString today = "2025-01-01";   // TODO: real date
    QString due   = "2025-01-15";   // today + 14

    QSqlQuery q;
    q.prepare("INSERT INTO Loans (user_id, item_id, issue_date, due_date, returned_date) "
              "VALUES (?, ?, ?, ?, NULL)");

    q.addBindValue(QVariant(patron->getDbId()));
    q.addBindValue(QVariant(item->getId()));
    q.addBindValue(today);
    q.addBindValue(due);

    if (!q.exec()) {
        qDebug() << "Failed to insert loan:" << q.lastError().text();
    }

    QSqlQuery q2;
    q2.prepare("UPDATE Catalogue SET available = 0 WHERE id = ?");
    q2.addBindValue(QVariant(item->getId()));
    if (!q2.exec()) {
        qDebug() << "Failed to update availability on checkout:"
                 << q2.lastError().text();
    }

    return true;
}


/*
int DataController::placeHold(int id, bool* b){
    Item* item = data.findItem(id);
    if(item == nullptr) return false;
    if(item->getAvailability()) return false;
    if(!patronAcc->addHold(item)) return false;
    item->addQueue(patronAcc);
    *b = true;
    return item->findIndex(patronAcc);
}

*/

bool DataController::placeHold(int id) {
    Item* item = data.findItem(id);
    if (!item) return false;

    Account* acc = getCurrentAccount();
    Patron* patron = dynamic_cast<Patron*>(acc);
    if (!patron) return false;

    // In-memory logic: enforce your rules
    if (!patron->addHold(item)) return false;
    item->addQueue(patron);     // or item->placeHold(patron);

    // === Persist to DB ===
    QSqlQuery q;

    // We can compute the position as current queue size.
    // If your Item exposes queue size, use that; otherwise we can count in SQL.
    int position = 1;

    // Option A: compute via SQL count
    QSqlQuery countQ;
    countQ.prepare("SELECT COUNT(*) FROM Holds WHERE item_id = ?");
    countQ.addBindValue(QVariant(item->getId()));
    if (countQ.exec() && countQ.next()) {
        position = countQ.value(0).toInt() + 1;
    }

    q.prepare("INSERT INTO Holds (user_id, item_id, position, created_at) "
              "VALUES (?, ?, ?, ?)");

    q.addBindValue(QVariant(patron->getDbId()));
    q.addBindValue(QVariant(item->getId()));
    q.addBindValue(QVariant(position));
    q.addBindValue(QString("2025-01-01"));  // TODO: real date string if you want

    if (!q.exec()) {
        qDebug() << "Failed to insert hold:" << q.lastError().text();
    }

    return true;
}



Patron* DataController::getCurrentAccount(){
    return patronAcc;
}

Patron* DataController::getPatronByName(const string& name)
{
    Account* target = data.findUser(name);
    if (target != nullptr && target->getAccountType() == PATRON) {
        // TODO: hmmm, i need type Patron, not Account...
    }
    return nullptr;
}

/*
void DataController::checkIn(int id) {
    Item* item = data.findItem(id);
    Patron* p = patronAcc; // cast to Patron

    if (!item || !p) return;
    p->checkIn(item);
    item->setAvailability(true);

    QSqlQuery q;
    q.prepare("UPDATE Loans "
              "SET returned_date = ? "
              "WHERE item_id = ? AND user_id = ? AND returned_date IS NULL");
    //q.addBindValue(QString::fromStdString(today.toString()));
    //q.addBindValue(item->getId());
    q.addBindValue(QVariant(item->getId()));
    q.addBindValue(p->getDbId());
    q.exec();

    QSqlQuery q2;
    q2.prepare("UPDATE Catalogue SET available = 1 WHERE id = ?");
    q2.addBindValue(item->getId());
    q2.exec();
}

*/

void DataController::checkIn(int id) {
    Item* item = data.findItem(id);
    if (!item) return;

    Account* acc = getCurrentAccount();
    Patron* patron = dynamic_cast<Patron*>(acc);
    if (!patron) return;

    // ==== 1) CURRENT PATRON RETURNS THE BOOK (in memory) ====
    patron->checkIn(item);
    item->setAvailability(true);

    // ==== 2) Mark the loan as returned in DB ====
    QString today = "2025-01-01";   // TODO: plug in real date

    QSqlQuery q;
    q.prepare("UPDATE Loans "
              "SET returned_date = ? "
              "WHERE item_id = ? AND user_id = ? AND returned_date IS NULL");

    q.addBindValue(today);
    q.addBindValue(QVariant(item->getId()));
    q.addBindValue(QVariant(patron->getDbId()));

    if (!q.exec()) {
        qDebug() << "Failed to mark loan returned:" << q.lastError().text();
    }

    QSqlQuery q2;
    q2.prepare("UPDATE Catalogue SET available = 1 WHERE id = ?");
    q2.addBindValue(QVariant(item->getId()));
    if (!q2.exec()) {
        qDebug() << "Failed to update availability:" << q2.lastError().text();
    }

}
//<<<<<<< HEAD

//=======
/*
>>>>>>> 9c47adc (D1 issue fixed)

/*
void DataController::cancelHold(int id){
    Item* item = data.findItem(id);
    item->removeQueue(patronAcc);
    patronAcc->removeHold(item);
}
*/
bool DataController::validateDate(int year, int month, int day){
    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1) {
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (isLeap) {
        daysInMonth[1] = 29;
    }

    if (day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

void DataController::addItem(const string &title, const string &author, int pub, long isbn,
                             const string &type, const string &dewy, int issueNumber, const string &pubDate, const string &genre, int rating){
    data.addItem(title, author, pub, isbn, type, dewy, issueNumber, pubDate, genre, rating);
}



void DataController::cancelHold(int id) {
    Item* item = data.findItem(id);
    if (!item) return;

    Account* acc = getCurrentAccount();
    Patron* patron = dynamic_cast<Patron*>(acc);
    if (!patron) return;

    // In-memory
    patron->removeHold(item);
    item->removeQueue(patron);   // or whatever your Item API uses

    // === Persist to DB ===
    QSqlQuery q;
    q.prepare("DELETE FROM Holds WHERE user_id = ? AND item_id = ?");

    q.addBindValue(QVariant(patron->getDbId()));
    q.addBindValue(QVariant(item->getId()));

    if (!q.exec()) {
        qDebug() << "Failed to delete hold:" << q.lastError().text();
    }

    data.renumberHoldsForItem(item->getId());

}








