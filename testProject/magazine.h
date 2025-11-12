#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "item.h"
#include "date.h"
#include <string>
class Magazine : public Item{
    public:
        Magazine(const std::string& name, const std::string& author, int year, int issue, const Date& pub, long isbn = 0);
        ~Magazine();
        virtual string display() const;

    private:
        int issueNumber;
        Date publication;

};
#endif
