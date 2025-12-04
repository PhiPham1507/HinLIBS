#include "book.h"
#include <string>
#include "fictionBook.h"
#include <iostream>


FictionBook::FictionBook(const std::string& name, const std::string& author, int year, long isbn) : Book(name, author, year, isbn){


}

FictionBook::~FictionBook(){}

string FictionBook::display()const{
    return "Title: " + title + ". Author: " + author + ". Publication Year: " + std::to_string(publicationYear)
            + ". Availability: " + available(availability) + "\n";
}
