#include "patron.h"
#include <string>
#include "item.h"
Patron::Patron(const string& username, const string& password) : Account(username, password)
{
    accountType = 0;

}
int Patron::getAccountType() const
{
    return accountType;
}
int Patron::getNumLoan(){
    return loans.size();
}

vector<Loan> Patron::getLoans()
{
    return loans;
}

vector<Item*> Patron::getHolds()
{
    return holds;
}

bool Patron::checkOut(Item *item){
    if(loans.size() >= 3) return false;
    Date checkout = Date();
    loans.push_back(Loan(item, checkout, checkout + 14));
    return true;
}

bool Patron::placeHold(Item *item){
    holds.push_back(item);
    return item->placeHold(this);
}


void Patron::addHold(Item *item){
    holds.push_back(item);
}
