#ifndef ACCOUNTDATABASE_H
#define ACCOUNTDATABASE_H

#include "Account.h"

// Very simple hard coded database for deliverable 1
struct accountInfo {
    char user[32];
    char pass[32];
    int type;
};

extern accountInfo accounts[3];
#endif // ACCOUNTDATABASE_H
