#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "item.h"

class Movie : public Item{
    public:
        Movie(const std::string& name, const std::string& author, int year, const std::string genre, int rating = -1, int isbn = 0);
        virtual ~Movie();
        virtual void display() const;
    private:
        std::string genre;
        int rating;

};
#endif
