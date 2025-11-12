#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include "Database.h"

class DataController
{
    public:
        DataController();
        void displayItems();
        void authenticate(const string& user, const string& pass);
        Account* getAccount();
        void accLoggedOut();

    private:
        Account* currentAccount;
        int itemSize;
        Database data;
};

#endif // AUTHENTICATOR_H
