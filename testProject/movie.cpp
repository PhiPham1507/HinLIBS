#include "movie.h"
#include "item.h"
#include <string>
#include <iostream>

Movie::Movie(const std::string& name, const std::string& author, int year, const std::string genre, int rating, long isbn) : Item(name, author, year, isbn), genre(genre), rating(rating){


}

Movie::~Movie(){}

string Movie::display()const{
    return "Title " + title + ". Author: " + author + ". Publication Year: " + std::to_string(publicationYear)
            + "Genre: " + genre + "Rating: " + std::to_string(rating) + "/10"
            + "  .Availability: " + available(availability) + "\n";}
