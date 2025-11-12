#include "item.h"
#include <string>
#include <iostream>

Item::Item(const std::string& name, const std::string& author, int year, long isbn) : title(name), author(author), publicationYear(year), isbn(isbn), availability(true)
{

}


Item::~Item(){


}
string Item::available(bool avail) const{
    return avail ? "Yes" : "No";
}

bool Item::getAvailability() const{
    return availability;
}
