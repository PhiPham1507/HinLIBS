#include "patron.h"
#include <string>
Patron::Patron(const string& username, const string& password) : Account(username, password)
{
    accountType = 0;
    numLoan = 0;
    //Was forced to initialize loans.
    for(int i = 0; i < 3; i++){
        loans[i] = Loan();
    }
}
int Patron::getAccountType() const
{
    return accountType;
}
int Patron::getNumLoan(){
    return numLoan;
}
bool Patron::checkOut(Item *item){
    if(numLoan >= 3) return false;
    Date checkout = Date();
    this->loans[numLoan++] = Loan(item, checkout, checkout + 14);
    return true;
}
