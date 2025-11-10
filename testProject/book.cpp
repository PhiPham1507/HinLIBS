#include "book.h"
#include <string>
Book::Book(const std::string& name, const std::string& author, int year, int isbn) : Item(name, author, year, isbn){

}

Book::~Book(){}

