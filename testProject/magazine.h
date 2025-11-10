#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "item.h"
class Magazine : public Item{
    public:
        Magazine(const std::string& name, const std::string& author, int year, int isbn = 0);
        ~Magazine();
        virtual void display() const;


    private:


};
#endif
