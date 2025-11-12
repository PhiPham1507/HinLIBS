#include "book.h"
#include "nonFictionBook.h"
#include <string>
#include <iostream>

NonFictionBook::NonFictionBook(const std::string& name, const std::string& author, const std::string& dewyD, int year, long isbn) : Book(name, author, year, isbn), dewy(dewyD){


}

NonFictionBook::~NonFictionBook(){}

string NonFictionBook::display()const{
    return "Title " + title + ". Author: " + author + ". Publication Year: " + std::to_string(publicationYear)
            + ". Dewy Decimal: " + " .Availability: " + available(availability) + "\n";}
