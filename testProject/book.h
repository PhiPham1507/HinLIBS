#ifndef BOOK_H
#define BOOK_H

#include "item.h"
#include <string>
class Book : public Item{

    public:
        Book(const std::string& name, const std::string& author, int year, int isbn = 0);
        ~Book();
        virtual string display() const = 0;

    private:



};

#endif
