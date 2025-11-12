#include "datacontroller.h"
#include <iostream>


DataController::DataController() : currentAccount(nullptr){
    itemSize = data.itemSize();
}

void DataController::displayItems(){
    for(int i = 0; i < itemSize; i++){
        cout << data.getItem(i)->display();
    }
}

void DataController::authenticate(const string &user, const string &pass){
    Account* findAcc = data.findUser(user);
    if(findAcc == nullptr) return;
    if(findAcc->getPassword() == pass){
        currentAccount = findAcc;
    }
}
Account* DataController::getAccount(){
    return currentAccount;
}
void DataController::accLoggedOut(){
    currentAccount = nullptr;
}
