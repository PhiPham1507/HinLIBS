#include "datacontroller.h"
#include <iostream>


DataController::DataController() : currentAccount(nullptr){
    itemSize = data.itemSize();
}

void DataController::setPatron(Patron *patron){
    currentAccount = patron;
}

void DataController::displayItems(){
    for(int i = 0; i < itemSize; i++){
        cout << data.getItem(i)->display();
    }
}

vector<Item*> DataController::getItems()
{
    vector<Item*> items;
    for (int i = 0; i < itemSize; ++i)
    {
        items.push_back(data.getItem(i));
    }

    return items;
}

bool DataController::getItemAvailability(int id)
{
    Item* item = data.findItem(id);
    if(item == nullptr) return false;
    return item->getAvailability();
}

Item* DataController::getItemById(int id)
{
    return data.findItem(id);
}

PatronDetails DataController::getPatronDetails()
{
    PatronDetails accDetails;
    accDetails.username = currentAccount->getAccountName();
    accDetails.loans = currentAccount->getLoans(); // shallow copy of loans
    accDetails.holds = currentAccount->getHolds(); // shallow copy of holds
    return accDetails;

}

Account* DataController::authenticate(const string &user, const string &pass){
    Account* findAcc = data.findUser(user);
    if(findAcc == nullptr) return nullptr;
    if(findAcc->getPassword() == pass){
        return findAcc;
    }else{
        return nullptr;
    }

}

void DataController::accLoggedOut(){
    currentAccount = nullptr;
}

bool DataController::checkOut(int id){
    Item* item = data.findItem(id);
    if(item == nullptr) return false;
    if(!item->getAvailability()) return false;
    bool patronCO = currentAccount->checkOut(item);
    if(!patronCO) return false;
    item->setAvailability(false);
    return true;

}

bool DataController::placeHold(int id){
    Item* item = data.findItem(id);
    if(item == nullptr) return false;
    if(item->getAvailability()) return false;
    return currentAccount->placeHold(item);
}

int DataController::placeHold(int id, bool* b){
    Item* item = data.findItem(id);
    if(item == nullptr) return false;
    if(!item->getAvailability()) return false;
    currentAccount->addHold(item);
    item->addQueue(currentAccount);
    *b = true;
    return item->findIndex(currentAccount);
}


