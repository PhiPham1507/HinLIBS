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

   private:
        int day, month, year;
};

#endif // DATE_H
