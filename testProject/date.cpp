#include "date.h"

Date::Date(const string& date){
    std::string s = date;
    sscanf(s.c_str(), "%d-%d-%d", &this->year, &this->month, &this->day);
}

const std::string Date::monthNames[12] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int Date::operator==(Date d)
{
    return (day == d.day && month == d.month && year == d.year);
}

int Date::operator!=(Date d)
{
    return !this->operator==(d);
}

Date Date::operator+(int day){
    Date result = *this;
    result.day += day;
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (result.year % 4 == 0 && (result.year % 100 != 0 || result.year % 400 == 0)) {
        daysInMonth[2] = 29;
    }
    while (result.day > daysInMonth[result.month]) {
            result.day -= daysInMonth[result.month];
            result.month++;

            if (result.month > 12) {
                result.month = 1;
                result.year++;

                // Recalculate leap year for new year
                if (result.year % 4 == 0 && (result.year % 100 != 0 || result.year % 400 == 0)) {
                    daysInMonth[2] = 29;
                } else {
                    daysInMonth[2] = 28;
                }
            }
        }
    return result;
}

int Date::operator<(Date d)
{
    // hahaha
    if (year < d.year) return 1;
    else if (year > d.year) return 0;
    else if (month < d.month) return 1;
    else if (month > d.month) return 0;
    else if (day < d.day) return 1;
    else if (day > d.day) return 0;
    else return !this->operator==(d);
}

int Date::operator<=(Date d)
{
    return (this->operator==(d) || this->operator<(d));
}

int Date::operator>(Date d)
{
    return !this->operator<=(d);
}

int Date::operator>=(Date d)
{
    return !this->operator<(d);
}

ostream& operator<<(ostream& os, const Date& d)
{
    //os << Date::monthNames[(d.month-1) % 12] << " " << d.day << ", " << d.year;
    os << d.getString();
    return os;
}
std::string Date::getString()const{
    return Date::monthNames[(this->month - 1) % 12] + " " + std::to_string(this->day) + ", " + std::to_string(this->year);
}

int Date::getDaysInMonth(int m, int y) const
{
    if (m == 2)
    {
        if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) return 29;
        else return 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    else return 31;
}
