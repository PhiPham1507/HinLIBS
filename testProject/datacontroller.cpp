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

bool DataController::checkOut(const string& str){
    Item* item = data.findItem(str);
    if(item == nullptr) return false;
    if(!item->getAvailability()) return false;
    bool patronCO = currentAccount->checkOut(item);
    if(!patronCO) return false;
    item->setAvailability(false);
    return true;

}

bool DataController::placeHold(const string& str){
    Item* item = data.findItem(str);
    if(item == nullptr) return false;
    if(!item->getAvailability()) return false;
    currentAccount->addHold(item);
    item->addQueue(currentAccount);
    return true;
}

