#ifndef DATE_H
#define DATE_H

#include <string>
#include "sstream"

using namespace std;

class Date {


   public:

        static const std::string monthNames[12];

        Date(int day, int month, int year) : day(day), month(month), year(year) {};
        Date() : day(1), month(1), year(1970) {};

        int operator==(Date d);
        int operator!=(Date d);
        int operator<=(Date d);
        int operator<(Date d);
        int operator>=(Date d);
        int operator>(Date d);
        friend ostream& operator<<(ostream& os, const Date& d);

        int getDay() const { return day; };
        int getMonth() const { return month; };
        int getYear() const {return year; };
        std::string getString() const;

        int getDaysInMonth(int m, int y) const;

   private:
        int day, month, year;
};

#endif // DATE_H
