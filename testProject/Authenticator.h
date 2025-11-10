#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "Account.h"
#include "AccountDatabase.h"

class Authenticator
{
public:

    static Account* requestSignIn(string username, string password);
    static void cleanup();

private:

    static Account* currentAccount;
};

#endif // AUTHENTICATOR_H
