#ifndef ADMIN_H
#define ADMIN_H
#include "Account.h"

class Admin : public Account
{
public:

    Admin(const string& username, const string& password);
    virtual int getAccountType() const;

private:


};

#endif // ADMIN_H

