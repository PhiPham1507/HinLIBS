#include "Account.h"

Account::Account(const string& username, const string& password): username(username), password(password)
{

}
Account::~Account()
{

}

const string& Account::getAccountName() const
{
    return username;
}
const string& Account::getPassword() const{
    return password;
}
