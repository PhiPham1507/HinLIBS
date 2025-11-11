#include "movie.h"
#include "item.h"
#include <string>
#include <iostream>

Movie::Movie(const std::string& name, const std::string& author, int year, const std::string genre, int rating, long isbn) : Item(name, author, year, isbn), genre(genre), rating(rating){


}

Movie::~Movie(){}

void Movie::display()const{
    std::cout << "Title: " << title << "\n";
}
