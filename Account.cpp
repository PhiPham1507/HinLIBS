#include "Account.h"

Account::Account()
{

}
Account::~Account()
{

}

const string& Account::getAccountName() const
{
    return username;
}
int Account::getAccountType() const
{
    return accountType;
}
