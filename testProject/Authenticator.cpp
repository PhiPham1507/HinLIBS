#include "Authenticator.h"

Authenticator::Authenticator()
{
    currentAccount = nullptr;
}

Authenticator::~Authenticator()
{
    if (currentAccount != nullptr) delete currentAccount;
}


Account* Authenticator::getCurrentAccount()
{
    return currentAccount;
}

// Checks the in-memory database to validate user credientials
bool Authenticator::requestSignIn(string username, string password)
{

    int accountIndex = -1;
    int length = sizeof(accounts) / sizeof(accountInfo);
    for (int i = 0; i < length; ++i)
    {
        if (username != accounts[i].user) continue;
        else if (password == accounts[i].pass)
        {
            accountIndex = i;
            break;
        }
    }


    if (accountIndex == -1) return false;

    //create account object and return account.
    if (currentAccount != nullptr) delete currentAccount;
    currentAccount = new Account(accounts[accountIndex].user, accounts[accountIndex].type);
    return true;

}

