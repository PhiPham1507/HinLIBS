#ifndef DATE_H
#define DATE_H

class Date {

   public:
        Date(int day, int month, int year) : day(day), month(month), year(year) {};
        Date() : day(1), month(1), year(1970) {};

        int operator==(Date d);
        int operator!=(Date d);
        int operator<=(Date d);
        int operator<(Date d);
        int operator>=(Date d);
        int operator>(Date d);

        int getDay() const { return day; };
        int getMonth() const { return month; };
        int getYear() const {return year; };

   private:
        int day, month, year;
};

#endif // DATE_H
