#include "item.h"
#include "magazine.h"
#include <string>
#include <iostream>

Magazine::Magazine(const std::string& name, const std::string& author, int year, int issue, Date& pub, int isbn) : Item(name, author, year, isbn),
    issueNumber(issue), publication(pub){


}

Magazine::~Magazine(){}

void Magazine::display()const{
    std::cout << "I am a Magazine";
}
