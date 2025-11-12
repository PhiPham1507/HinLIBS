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
    int getNumLoan();
    bool checkOut(Item* item);

private:
    Loan loans[3];
    int numLoan;
    vector<Item*> holds;

};

#endif // PATRON_H
