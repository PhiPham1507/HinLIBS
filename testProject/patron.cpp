#include "patron.h"
#include <string>
Patron::Patron(const string& username, const string& password) : Account(username, password)
{
    accountType = 0;
}
int Patron::getAccountType() const
{
    return accountType;
}
