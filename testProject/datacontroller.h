#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include "Database.h"
#include "patron.h"

class DataController
{
    public:
        DataController();
        void displayItems();
        void setPatron(Patron* patron);
        Account* authenticate(const string& user, const string& pass);
        void accLoggedOut();
        bool checkOut(const string& str);

    private:
        Patron* currentAccount;
        int itemSize;
        Database data;
};

#endif // AUTHENTICATOR_H
