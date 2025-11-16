#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>
#include "date.h"


class Patron;
class Item
{


    public:

        static int idCount;

        Item(const std::string& name, const std::string& author, int year, long isbn = 0);
        virtual ~Item();
        string available(bool avail) const;
        int getId() const;
        bool getAvailability() const;
        bool placeHold(Patron* patron);
        void addQueue(Patron* patron);
        void setAvailability(bool b);
        int findIndex(Patron* patron);
        void removeQueue(Patron* patron);
        string& getTitle();
        virtual string display() const = 0;

    protected:
        std::string title;
        std::string author;
        int publicationYear;
        long isbn;
        bool availability;
        Date dueDate;
        vector<Patron*> queue;
        int id;

};

#endif // ITEM_H
