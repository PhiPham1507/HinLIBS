#include "item.h"
#include "magazine.h"
#include <string>
#include <iostream>

Magazine::Magazine(const std::string& name, const std::string& author, int year, int issue, const Date& pub, long isbn) : Item(name, author, year, isbn),
    issueNumber(issue), publication(pub){

}

Magazine::~Magazine(){}

void Magazine::display()const{
    std::cout << "Title: " << title << "\n";
}
