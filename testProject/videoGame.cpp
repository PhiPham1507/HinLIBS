#include "videoGame.h"
#include "item.h"
#include <string>
#include <iostream>


VideoGame::VideoGame(const std::string& name, const std::string& author, int year, const std::string genre, int rating, long isbn) : Item(name, author, year, isbn), genre(genre), rating(rating){


}

VideoGame::~VideoGame(){}

void VideoGame::display()const{
    std::cout << "Title " << title << "\n";

}
