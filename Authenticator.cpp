#include "Authenticator.h"

Authenticator::Authenticator()
{
    currentAccount = nullptr;
}

Authenticator::~Authenticator()
{
    delete currentAccount;
}

// Checks the in-memory database to validate user credientials
Account* Authenticator::requestSignIn(string username, string password)
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


    if (accountIndex == -1) return nullptr;

    //create account object and return account.
    if (currentAccount != nullptr) delete currentAccount;
    currentAccount = new Account(accounts[accountIndex].user, accounts[accountIndex].type);
    return currentAccount;

}
