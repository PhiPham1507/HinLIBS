#include "item.h"
#include <string>
#include <iostream>
#include "patron.h"

int Item::idCount = 0;

Item::Item(const std::string& name, const std::string& author, int year, long isbn) : title(name), author(author), publicationYear(year), isbn(isbn), availability(true)
{
    Item::idCount++;
    id = Item::idCount;
}


Item::~Item(){


}

int Item::getId() const
{
    return id;
}

string Item::available(bool avail) const{
    return avail ? "Yes" : "No";
}

bool Item::getAvailability() const{
    return availability;
}

bool Item::placeHold(Patron *patron){
    queue.push_back(patron);
    this->availability = false;
    return true;
}
void Item::addQueue(Patron *patron){
    queue.push_back(patron);
}
void Item::setAvailability(bool b){
    availability = b;
}
int Item::findIndex(Patron *patron){
    int i = 1;
    for(Patron* p : queue){
        if(p->getAccountName() == patron->getAccountName()){
            return i;
        }
        i++;
    }
    return i;
}

