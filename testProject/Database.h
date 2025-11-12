#ifndef DATABASE_H
#define DATABASE_H

#include "Account.h"
#include <vector>
#include "item.h"
#include "Account.h"

class Database {
public:
    Database();
    ~Database();
    int itemSize();
    Item* getItem(int i);
    Account* findUser(const string& username);
private:
    vector<Item*> items;
    vector<Account*> accounts;


};
#endif
