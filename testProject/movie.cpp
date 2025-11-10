#include "movie.h"
#include "item.h"
#include <string>
#include <iostream>

Movie::Movie(const std::string& name, const std::string& author, int year, const std::string genre, int rating, int isbn) : Item(name, author, year, isbn), genre(genre), rating(rating){


}

Movie::~Movie(){}

void Movie::display()const{
    std::cout << "I am a movie";
}
