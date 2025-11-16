#ifndef PATRON_H
#define PATRON_H

#include "Account.h"
#include "loan.h"
#include <vector>

// use this struct to return account status to the patron
struct PatronDetails {
    string username;
    vector<Loan> loans;
    vector<Item*> holds;
};

class Item;
class Patron : public Account
{
public:
    Patron(const string& username, const string& password);
    virtual int getAccountType() const;
    int getNumLoan();
    int getNumHold();
    vector<Loan> getLoans();
    vector<Item*> getHolds();
    void checkIn(Item* item);
    void removeHold(Item* item);

    bool checkOut(Item* item);
    bool addHold(Item* item);



private:

    vector<Loan> loans;
    vector<Item*> holds;

};

#endif // PATRON_H
