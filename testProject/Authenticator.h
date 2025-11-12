#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "AccountDatabase.h"

class Authenticator
{
    public:
        Authenticator();
        ~Authenticator();

        bool requestSignIn(string username, string password);
        bool signOut();
        Account* getCurrentAccount();


    private:
        Account* currentAccount;
};

#endif // AUTHENTICATOR_H
