 #include "datacontroller.h"
#include <QtSql/qsqlquery.h>
#include <iostream>

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

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

bool DataController::checkOut(int id){
    Item* item = data.findItem(id);
    if(item == nullptr) return false;
    if(!item->getAvailability()) return false;
    bool patronCO = patronAcc->checkOut(item);
    if(!patronCO) return false;
    item->setAvailability(false);
    return true;
}



int DataController::placeHold(int id, bool* b){
    Item* item = data.findItem(id);
    if(item == nullptr) return false;
    if(item->getAvailability()) return false;
    if(!patronAcc->addHold(item)) return false;
    item->addQueue(patronAcc);
    *b = true;
    return item->findIndex(patronAcc);
}

Patron* DataController::getCurrentAccount(){
    return patronAcc;
}

Patron* DataController::getPatronByName(const string& name)
{
    Account* target = data.findUser(name);
    if (target != nullptr && target->getAccountType() == PATRON) {
        // TODO: hmmm
    }
    return nullptr;
}

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

void DataController::cancelHold(int id){
    Item* item = data.findItem(id);
    item->removeQueue(patronAcc);
    patronAcc->removeHold(item);
}












