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
        vector<Item*> getItems();
        bool getItemAvailability(int id);
        Item* getItemById(int id);
        //PatronDetails getPatronDetails();
        Account* authenticate(const string& user, const string& pass);
        void accLoggedOut();
        bool checkOut(int id);
        void checkIn(int id);
        void cancelHold(int id);
        int placeHold(int id, bool* b);
        Patron* getCurrentAccount();


    private:
        Patron* currentAccount;
        int itemSize;
        Database data;
};

#endif // AUTHENTICATOR_H
