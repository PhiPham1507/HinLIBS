#include "item.h"
#include "magazine.h"
#include <string>
#include <iostream>

Magazine::Magazine(const std::string& name, const std::string& author, int year, int issue, const Date& pub, long isbn) : Item(name, author, year, isbn),
    issueNumber(issue), publication(pub){

}

Magazine::~Magazine(){}

string Magazine::display()const{
    return "Title: " + title + ". Author: " + author + ". Publication Year: " + std::to_string(publicationYear)
            + ". Issue Number: " + std::to_string(issueNumber) + publication.getString()
            + ". Availability: " + available(availability) + "\n";}
