#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include "Database.h"
#include "patron.h"
#include "librarian.h"

class DataController
{
    public:
        DataController();
        void displayItems();
        void setPatron(Patron* patron);
        void setLibrarian(Librarian* lib);
        vector<Item*> getItems(); //Temporary
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
        void removeItem(int index);
        Patron* getPatronByName(const string& name);
        Database& getDatabase() {return data;}
        bool validateDate(int year, int month, int day);
        void addItem(const string& title, const string& author, int pub, long isbn, const string& type,const string& dewy, int issueNumber, const string& pubDate, const string& genre, int rating);


    private:
        Patron* patronAcc;
        Librarian* libAcc;
        int itemSize;
        Database data;
};

#endif // AUTHENTICATOR_H
