#ifndef PATRON_H
#define PATRON_H

#include "Account.h"
#include "loan.h"

class Patron : public Account
{
public:
    Patron(const string& username, const string& password);
    virtual int getAccountType() const;

private:
    Loan loans[3];

};

#endif // PATRON_H
