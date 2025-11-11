#ifndef NONFICTIONBOOK_H
#define NONFICTIONBOOK_H
#include <string>
#include "book.h"

class NonFictionBook : public Book{
    public:
        NonFictionBook(const std::string& name, const std::string& author, const std::string& dewyD, int year, long isbn = 0);
        virtual ~NonFictionBook();
        virtual void display() const;
    private:
        std::string dewy;

};
#endif
