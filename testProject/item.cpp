#include "item.h"
#include <string>
#include <iostream>

Item::Item(const std::string& name, const std::string& author, int year, int isbn) : title(name), author(author), publicationYear(year), isbn(isbn), availability(true)
{

}


Item::~Item(){


}
