#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "Account.h"
#include "AccountDatabase.h"

class Authenticator
{
public:
    Authenticator();
    ~Authenticator();

    Account* requestSignIn(string username, string password);

private:

    Account* currentAccount;
};

#endif // AUTHENTICATOR_H
