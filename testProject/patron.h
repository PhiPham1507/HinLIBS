#ifndef PATRON_H
#define PATRON_H

#include "Account.h"
#include "loan.h"
#include <vector>
#include "item.h"

class Patron : public Account
{
public:
    Patron(const string& username, const string& password);
    virtual int getAccountType() const;

private:
    Loan loans[3];
    int numLoan;
    vector<Item*> holds;

};

#endif // PATRON_H
