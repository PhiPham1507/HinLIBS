#include "date.h"

int Date::operator==(Date d)
{
    return (day == d.day && month == d.month && year == d.year);
}

int Date::operator!=(Date d)
{
    return !this->operator==(d);
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

