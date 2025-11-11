#include "book.h"
#include "nonFictionBook.h"
#include <string>
#include <iostream>

NonFictionBook::NonFictionBook(const std::string& name, const std::string& author, const std::string& dewyD, int year, long isbn) : Book(name, author, year, isbn), dewy(dewyD){


}

NonFictionBook::~NonFictionBook(){}

void NonFictionBook::display()const{
    std::cout << "Title " << title << "\n";
}
