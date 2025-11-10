#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

#include <string>
#include "book.h"

class FictionBook : public Book{
    public:
        FictionBook(const std::string& name, const std::string& author, int year, int isbn = 0);
        virtual ~FictionBook();
        virtual void display() const;
    private:


};
#endif
