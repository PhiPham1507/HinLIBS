#ifndef DATABASE_H
#define DATABASE_H

#include "Account.h"
#include <vector>
#include "item.h"
#include "Account.h"
#include <QSqlDatabase>

class Database {
public:
    Database();
    ~Database();

    int itemSize();
    Item* getItem(int i);
    Item* findItem(int id) const;
    Account* findUser(const string& username);

    void printDatabase();

private:
    void openConnection();
    void initializeSchemaIfNeeded();
    void loadUsers();
    void loadItems();
    void loadLoansAndHolds();

    QSqlDatabase db;
    vector<Item*> items;
    vector<Account*> accounts;


};
#endif
