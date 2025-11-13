#ifndef PATRON_H
#define PATRON_H

#include "Account.h"
#include "loan.h"
#include <vector>


class Item;
class Patron : public Account
{
public:
    Patron(const string& username, const string& password);
    virtual int getAccountType() const;
    int getNumLoan();
    bool checkOut(Item* item);
    void addHold(Item* item);
private:
    vector<Loan> loans;
    vector<Item*> holds;

};

#endif // PATRON_H
