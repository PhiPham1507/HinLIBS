#include "Database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QSqlRecord>



#include <vector>
#include "fictionBook.h"
#include "nonFictionBook.h"
#include "magazine.h"
#include "videoGame.h"
#include "movie.h"
#include "patron.h"
#include "librarian.h"
#include "admin.h"
#include <iostream>

Database::Database(){

    openConnection();
    initializeSchemaIfNeeded();
    loadUsers();
    loadItems();
    loadLoansAndHolds();
/*

    items.push_back(new FictionBook("Catcher in the Rye", "J.D. Salinger", 1951, 9780316769488));
    items.push_back(new FictionBook("To Kill a Mockingbird", "Harper Lee", 1960, 9780061120084));
    items.push_back(new FictionBook("1984", "George Orwell", 1949, 9780451524935));
    items.push_back(new FictionBook("Brave New World", "Aldous Huxley", 1932, 9780060850524));
    items.push_back(new FictionBook("The Great Gatsby", "F. Scott Fitzgerald", 1925, 9780743273565));
    items.push_back(new NonFictionBook("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", "303", 2011, 9780062316097));
    items.push_back(new NonFictionBook("Educated", "Tara Westover", "371.4", 2018, 9780399590504));
    items.push_back(new NonFictionBook("The Immortal Life of Henrietta Lacks", "Rebecca Skloot", "616.0276", 2010, 9781400052189));
    items.push_back(new NonFictionBook("Thinking, Fast and Slow", "Daniel Kahneman", "153.4", 2011, 9780374533557));
    items.push_back(new NonFictionBook("Guns, Germs, and Steel", "Jared Diamond", "909", 1997, 9780393317558));
    items.push_back(new Magazine("National Geographic", "Various Authors", 2025, 3, Date(15,3,2025), 9781426217782));
    items.push_back(new Magazine("Time", "Various Authors", 2025, 7, Date(1,7,2025), 9781618935763));
    items.push_back(new Magazine("The New Yorker", "Various Authors", 2025, 20, Date(20,10,2025), 9781640970902));
    items.push_back(new Movie("The Shawshank Redemption", "Frank Darabont", 1994, "Drama", 9, 9780786012672));
    items.push_back(new Movie("Inception", "Christopher Nolan", 2010, "Sci-Fi", 8, 9780812997392));
    items.push_back(new Movie("The Godfather", "Francis Ford Coppola", 1972, "Crime", 10, 9780451205766));
    items.push_back(new VideoGame("The Legend of Zelda: Breath of the Wild", "Nintendo", 2017, "Action-Adventure", 10, 9781770150457));
    items.push_back(new VideoGame("The Witcher 3: Wild Hunt", "CD Projekt", 2015, "RPG", 9, 9781785291212));
    items.push_back(new VideoGame("Minecraft", "Mojang Studios", 2011, "Sandbox", 8, 9780692335976));
    items.push_back(new VideoGame("God of War", "Santa Monica Studio", 2018, "Action", 9, 9781506716439));

    accounts.push_back(new Patron("john323", "littlejohn"));
    accounts.push_back(new Patron("dane113", "dane"));
    accounts.push_back(new Patron("littlehenry", "henry16"));
    accounts.push_back(new Patron("harry9", "hair"));
    accounts.push_back(new Patron("moneylover", "$$"));
    accounts.push_back(new Librarian("lib1", "lib1"));
    accounts.push_back(new Admin("admin1", "admin1"));

*/
}
Database::~Database(){
    if(db.isOpen()) db.close();
}

Item* Database::getItem(int i){
    return items.at(i);
}
int Database::itemSize(){
    return items.size();
}
vector<Item*> Database::getItems(){
    return items;
}

Account* Database::findUser(const string &username){
    for(Account* acc: accounts){
        if(acc->getAccountName() == username){
            return acc;
        }
    }
    return nullptr;
}
void Database::removeItem(int id){
    for(unsigned long i = 0; i < items.size(); i++){
        if(items.at(i)->getId() == id){
            items.erase(items.begin() + i);
            cout << "Found" << endl;
            //remove from the database
            return;
        }
    }
}
Item* Database::findItem(int id) const{
    for(Item* item : items){
        if(item->getId() == id) return item;
    }
    return nullptr;
}


void Database::openConnection(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("hinlibs.db");

    if(!db.open()){
        qDebug() << "Failed to open DB: " << db.lastError().text();
        // handle error gracefully
    }
}

void Database::initializeSchemaIfNeeded() {
    QSqlQuery q;

    // Create tables (IF NOT EXISTS)
    q.exec("CREATE TABLE IF NOT EXISTS Users ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT,"
           "username TEXT UNIQUE NOT NULL,"
           "password TEXT NOT NULL,"
           "role TEXT NOT NULL,"
           "fines_cents INTEGER NOT NULL DEFAULT 0)");

    q.exec("CREATE TABLE IF NOT EXISTS Catalogue ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT,"
           "title TEXT NOT NULL,"
           "author TEXT,"
           "publication_year INTEGER,"
           "isbn TEXT,"
           "type TEXT NOT NULL,"
           "dewey TEXT,"
           "issue_number INTEGER,"
           "publication_date TEXT,"
           "genre TEXT,"
           "rating INTEGER,"
           "available INTEGER NOT NULL DEFAULT 1)");

    q.exec("CREATE TABLE IF NOT EXISTS Loans ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT,"
           "user_id INTEGER NOT NULL,"
           "item_id INTEGER NOT NULL,"
           "issue_date TEXT NOT NULL,"
           "due_date TEXT NOT NULL,"
           "returned_date TEXT,"
           "FOREIGN KEY(user_id) REFERENCES Users(id),"
           "FOREIGN KEY(item_id) REFERENCES Catalogue(id))");

    q.exec("CREATE TABLE IF NOT EXISTS Holds ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT,"
           "user_id INTEGER NOT NULL,"
           "item_id INTEGER NOT NULL,"
           "position INTEGER NOT NULL,"
           "created_at TEXT NOT NULL,"
           "FOREIGN KEY(user_id) REFERENCES Users(id),"
           "FOREIGN KEY(item_id) REFERENCES Catalogue(id))");

    // Check if Users table is empty; if so, seed default data
    if (q.exec("SELECT COUNT(*) FROM Users") && q.next()) {
        int count = q.value(0).toInt();
        if (count == 0) {
            qDebug() << "Seeding default Users and Catalogue data...";

            // Optional, but nice: wrap seed in a transaction
            db.transaction();

            // ---------- Seed Users ----------
            QSqlQuery uq;
            uq.prepare("INSERT INTO Users (username, password, role, fines_cents) "
                       "VALUES (?, ?, ?, 0)");

            auto addUser = [&](const QString& username,
                               const QString& password,
                               const QString& role) {
                uq.bindValue(0, username);
                uq.bindValue(1, password);
                uq.bindValue(2, role);
                if (!uq.exec()) {
                    qDebug() << "Failed to insert user" << username << ":" << uq.lastError().text();
                }
            };

            // 5 patrons
            addUser("john323",      "littlejohn", "patron");
            addUser("dane113",      "dane",       "patron");
            addUser("littlehenry",  "henry16",    "patron");
            addUser("harry9",       "hair",       "patron");
            addUser("moneylover",   "$$",         "patron");

            // 1 librarian
            addUser("lib1",         "lib1",       "librarian");

            // 1 admin
            addUser("admin1",       "admin1",     "admin");

            // ---------- Seed Catalogue ----------
            QSqlQuery cq;
            cq.prepare("INSERT INTO Catalogue "
                       "(title, author, publication_year, isbn, type, "
                       " dewey, issue_number, publication_date, genre, rating, available) "
                       "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, 1)");

            auto addItem = [&](const QString& title,
                               const QString& author,
                               int year,
                               const QString& isbn,
                               const QString& type,
                               const QVariant& dewey,
                               const QVariant& issueNumber,
                               const QVariant& publicationDate,
                               const QVariant& genre,
                               const QVariant& rating) {
                cq.bindValue(0, title);
                cq.bindValue(1, author);
                cq.bindValue(2, year);
                cq.bindValue(3, isbn);
                cq.bindValue(4, type);
                cq.bindValue(5, dewey);
                cq.bindValue(6, issueNumber);
                cq.bindValue(7, publicationDate);
                cq.bindValue(8, genre);
                cq.bindValue(9, rating);

                if (!cq.exec()) {
                    qDebug() << "Failed to insert item" << title << ":" << cq.lastError().text();
                }
            };

            // 5 fiction books
            addItem("Catcher in the Rye", "J.D. Salinger", 1951, "9780316769488",
                    "fiction", QVariant(), QVariant(), QVariant(), QVariant(), QVariant());
            addItem("To Kill a Mockingbird", "Harper Lee", 1960, "9780061120084",
                    "fiction", QVariant(), QVariant(), QVariant(), QVariant(), QVariant());
            addItem("1984", "George Orwell", 1949, "9780451524935",
                    "fiction", QVariant(), QVariant(), QVariant(), QVariant(), QVariant());
            addItem("Brave New World", "Aldous Huxley", 1932, "9780060850524",
                    "fiction", QVariant(), QVariant(), QVariant(), QVariant(), QVariant());
            addItem("The Great Gatsby", "F. Scott Fitzgerald", 1925, "9780743273565",
                    "fiction", QVariant(), QVariant(), QVariant(), QVariant(), QVariant());

            // 5 non-fiction books (with Dewey)
            addItem("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 2011, "9780062316097",
                    "nonfiction", "303", QVariant(), QVariant(), QVariant(), QVariant());
            addItem("Educated", "Tara Westover", 2018, "9780399590504",
                    "nonfiction", "371.4", QVariant(), QVariant(), QVariant(), QVariant());
            addItem("The Immortal Life of Henrietta Lacks", "Rebecca Skloot", 2010, "9781400052189",
                    "nonfiction", "616.0276", QVariant(), QVariant(), QVariant(), QVariant());
            addItem("Thinking, Fast and Slow", "Daniel Kahneman", 2011, "9780374533557",
                    "nonfiction", "153.4", QVariant(), QVariant(), QVariant(), QVariant());
            addItem("Guns, Germs, and Steel", "Jared Diamond", 1997, "9780393317558",
                    "nonfiction", "909", QVariant(), QVariant(), QVariant(), QVariant());

            // 3 magazines (issue_number + publication_date)
            addItem("National Geographic", "Various Authors", 2025, "9781426217782",
                    "magazine", QVariant(), 3, "2025-03-15", QVariant(), QVariant());
            addItem("Time", "Various Authors", 2025, "9781618935763",
                    "magazine", QVariant(), 7, "2025-07-01", QVariant(), QVariant());
            addItem("The New Yorker", "Various Authors", 2025, "9781640970902",
                    "magazine", QVariant(), 20, "2025-10-20", QVariant(), QVariant());

            // 3 movies (genre + rating)
            addItem("The Shawshank Redemption", "Frank Darabont", 1994, "9780786012672",
                    "movie", QVariant(), QVariant(), QVariant(), "Drama", 9);
            addItem("Inception", "Christopher Nolan", 2010, "9780812997392",
                    "movie", QVariant(), QVariant(), QVariant(), "Sci-Fi", 8);
            addItem("The Godfather", "Francis Ford Coppola", 1972, "9780451205766",
                    "movie", QVariant(), QVariant(), QVariant(), "Crime", 10);

            // 4 video games (genre + rating)
            addItem("The Legend of Zelda: Breath of the Wild", "Nintendo", 2017, "9781770150457",
                    "videogame", QVariant(), QVariant(), QVariant(), "Action-Adventure", 10);
            addItem("The Witcher 3: Wild Hunt", "CD Projekt", 2015, "9781785291212",
                    "videogame", QVariant(), QVariant(), QVariant(), "RPG", 9);
            addItem("Minecraft", "Mojang Studios", 2011, "9780692335976",
                    "videogame", QVariant(), QVariant(), QVariant(), "Sandbox", 8);
            addItem("God of War", "Santa Monica Studio", 2018, "9781506716439",
                    "videogame", QVariant(), QVariant(), QVariant(), "Action", 9);

            if (!db.commit()) {
                qDebug() << "Failed to commit seed transaction:" << db.lastError().text();
            } else {
                qDebug() << "Seeding complete.";
            }
        }
    }

}

void Database::loadUsers() {
    QSqlQuery q("SELECT id, username, password, role FROM Users");

    while (q.next()) {
        int id             = q.value(0).toInt();
        std::string uname  = q.value(1).toString().toStdString();
        std::string pass   = q.value(2).toString().toStdString();
        std::string role   = q.value(3).toString().toStdString();

        Account* acc = nullptr;
        if (role == "patron") {
            acc = new Patron(uname, pass);
        } else if (role == "librarian") {
            acc = new Librarian(uname, pass);
        } else if (role == "admin") {
            acc = new Admin(uname, pass);
        }

        if (acc) {
            // If you want to store DB id inside Account, add a field + setter.
            accounts.push_back(acc);
        }
    }
}


void Database::loadItems() {
    QSqlQuery q("SELECT id, title, author, publication_year, isbn,"
                "       type, dewey, issue_number, publication_date,"
                "       genre, rating, available "
                "FROM Catalogue");

    while (q.next()) {
        int id               = q.value(0).toInt();
        std::string title    = q.value(1).toString().toStdString();
        std::string author   = q.value(2).toString().toStdString();
        int year             = q.value(3).toInt();
        long isbn            = q.value(4).toString().toLongLong();
        std::string type     = q.value(5).toString().toStdString();
        std::string dewey    = q.value(6).toString().toStdString();
        int issueNumber      = q.value(7).toInt();
        QString pubDateStr   = q.value(8).toString();
        std::string genre    = q.value(9).toString().toStdString();
        int rating           = q.value(10).toInt();
        bool available       = q.value(11).toInt() != 0;

        Item* item = nullptr;

        if (type == "fiction") {
            item = new FictionBook(title, author, year, isbn);
        } else if (type == "nonfiction") {
            item = new NonFictionBook(title, author, dewey, year, isbn);
        } else if (type == "magazine") {
            // Convert pubDateStr ("YYYY-MM-DD") into your Date class
            //Date pubDate;  // TODO: parse string into Date
            item = new Magazine(title, author, year, issueNumber, Date(pubDateStr.toStdString()), isbn);
        } else if (type == "movie") {
            item = new Movie(title, author, year, genre, rating, isbn);
        } else if (type == "videogame") {
            item = new VideoGame(title, author, year, genre, rating, isbn);
        }

        if (item) {
            item->setAvailability(available);
            item->setId(id);       // add setter or adjust constructor so DB id and static idCount align
            items.push_back(item);
        }
    }
}


void Database::loadLoansAndHolds() {
    // 1) Loans
    QSqlQuery q1("SELECT user_id, item_id, issue_date, due_date "
                 "FROM Loans WHERE returned_date IS NULL");

    while (q1.next()) {
        int userId  = q1.value(0).toInt();
        int itemId  = q1.value(1).toInt();
        QString issue = q1.value(2).toString();
        QString due   = q1.value(3).toString();

        // Find Account/Patron* and Item*
        // Then construct Loan(item, issueDate, dueDate) and push into Patron.loans
    }

    // 2) Holds
    QSqlQuery q2("SELECT user_id, item_id, position "
                 "FROM Holds ORDER BY item_id, position ASC");

    while (q2.next()) {
        int userId = q2.value(0).toInt();
        int itemId = q2.value(1).toInt();
        int pos    = q2.value(2).toInt();

        // Find Patron* and Item* and reconstruct Item::queue and Patron.holds
    }
}

void Database::printDatabase() {
    auto printTable = [&](const QString& name) {
        qDebug() << "\n---" << name << "---";

        QSqlQuery q(QString("SELECT * FROM %1").arg(name));
        if (!q.exec()) {
            qDebug() << "Query failed for" << name << ":" << q.lastError().text();
            return;
        }

        QSqlRecord rec = q.record();
        QString header;

        // Column names
        for (int i = 0; i < rec.count(); ++i) {
            header += rec.fieldName(i) + "\t";
        }
        qDebug().noquote() << header;

        // Rows
        while (q.next()) {
            QString row;
            for (int i = 0; i < rec.count(); ++i) {
                row += q.value(i).toString() + "\t";
            }
            qDebug().noquote() << row;
        }
    };

    printTable("Users");
    printTable("Catalogue");
    printTable("Loans");
    printTable("Holds");
}
void Database::addItem(const string &title, const string &author, int pub, long isbn, const string &type, const string &dewy,
                       int issueNumber, const string &pubDate, const string &genre, int rating){
    if(type == "fiction"){
        //Add to database directly instead of creating the item and push to vector. This is temporary for testing
        Item* item = new FictionBook(title, author, pub, isbn);
        item->setId(items.at(items.size() - 1)->getId() + 1);
        items.push_back(item);
    }else if(type == "nonfiction"){
        Item* item = new NonFictionBook(title, author, dewy, pub, isbn);
        item->setId(items.at(items.size() - 1)->getId() + 1);
        items.push_back(item);
    }else if(type == "videogame"){
        Item* item = new VideoGame(title,author,pub,genre, rating, isbn);
        item->setId(items.at(items.size() - 1)->getId() + 1);
        items.push_back(item);
    }else if(type == "movie"){
        Item* item = new Movie(title,author,pub, genre, rating, isbn);
        item->setId(items.at(items.size() - 1)->getId() + 1);
        items.push_back(item);
    }else{
        Item* item = new Magazine(title,author,pub,issueNumber,Date(pubDate), isbn);
        item->setId(items.at(items.size() - 1)->getId() + 1);
        items.push_back(item);
    }
}
