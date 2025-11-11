#include "datacontroller.h"


DataController::DataController() : currentAccount(nullptr){

}

void DataController::displayItems(){
    data.displayItems();
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
