#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "Account.h"

class Librarian : public Account
{
public:

    Librarian(const string& username, const string& password);
    virtual int getAccountType() const;

private:


};

#endif // LIBRARIAN_H
