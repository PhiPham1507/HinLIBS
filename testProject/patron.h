#ifndef PATRON_H
#define PATRON_H

#include "Account.h"
#include "loan.h"

class Patron : public Account
{
public:
    Patron() : Account();

private:
    Loan loans[3];
};

#endif // PATRON_H
