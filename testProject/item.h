#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <queue>

class Item
{
    public:
        Item(const std::string& name, const std::string& author, int year, int isbn = 0);
        virtual ~Item();

        virtual void display() const = 0;

    private:
        std::string title;
        std::string author;
        int publicationYear;
        int isbn;
        //Date dueDate;
        //std::queue<Account*> queue;

};

#endif // ITEM_H
