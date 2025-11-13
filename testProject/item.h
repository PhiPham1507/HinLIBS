#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>
#include "patron.h"
#include "date.h"

class Item
{
    public:
        Item(const std::string& name, const std::string& author, int year, long isbn = 0);
        virtual ~Item();
        string available(bool avail) const;
        bool getAvailability() const;
        void addQueue(Patron* patron);
        void setAvailability(bool b);

        virtual string display() const = 0;

    protected:
        std::string title;
        std::string author;
        int publicationYear;
        long isbn;
        bool availability;
        Date dueDate;
        vector<Patron*> queue;

};

#endif // ITEM_H
