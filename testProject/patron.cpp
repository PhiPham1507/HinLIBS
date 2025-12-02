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

int Patron::getNumHold(){
    return holds.size();
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




bool Patron::addHold(Item *item){
    for(Item* holded : holds){
        if(holded->getId() == item->getId()){
            return false;
        }
    }
    for(Loan l : loans){
        if(l.getItem()->getId() == item->getId()){
            return false;
        }
    }
    holds.push_back(item);
    return true;
}

void Patron::checkIn(Item *item){
    for(int i = 0; i < getNumLoan(); i++){
        if(loans.at(i).getItem()->getId() == item->getId()){
            loans.erase(loans.begin() + i);
            return;
        }
    }
}

void Patron::removeHold(Item *item){
    for(int i = 0; i < getNumHold(); i++){
        if(holds.at(i)->getId() == item->getId()){
            holds.erase(holds.begin() + i);
            return;
        }

    }
}


void Patron::addExistingLoan(Item* item) {
    Date checkout = Date();           // you can get real dates later
    loans.push_back(Loan(item, checkout, checkout + 14));
}

void Patron::addExistingHold(Item* item){
    holds.push_back(item);
}


