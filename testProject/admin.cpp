#include "admin.h"

Admin::Admin(const string& username, const string& password) : Account(username, password)
{
    accountType = 2;
}
int Admin::getAccountType() const
{
    return accountType;
}
