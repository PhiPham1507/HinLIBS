#include "librarian.h"

Librarian::Librarian(const string& username, const string& password) : Account(username, password)
{
    accountType = 1;
}
int Librarian::getAccountType() const
{
    return accountType;
}
