#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <queue>
#include "date.h"

class Item
{
    public:
        Item(const std::string& name, const std::string& author, int year, long isbn = 0);
        virtual ~Item();

        virtual void display() const = 0;

    protected:
        std::string title;
        std::string author;
        int publicationYear;
        long isbn;
        bool availability;
        Date dueDate;
        //std::queue<Account*> queue;

};

#endif // ITEM_H
