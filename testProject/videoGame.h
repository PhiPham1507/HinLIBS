#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <string>
#include "item.h"

class VideoGame : public Item{
    public:
        VideoGame(const std::string& name, const std::string& author, int year, const std::string genre, int rating = -1, int isbn = 0);
        virtual ~VideoGame();
        virtual void display() const;
    private:
        std::string genre;
        int rating;

};
#endif
