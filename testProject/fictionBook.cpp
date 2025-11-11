#include "book.h"
#include <string>
#include "fictionBook.h"
#include <iostream>


FictionBook::FictionBook(const std::string& name, const std::string& author, int year, long isbn) : Book(name, author, year, isbn){


}

FictionBook::~FictionBook(){}

void FictionBook::display()const{
    std::cout << "Title " << title << "\n";
}
