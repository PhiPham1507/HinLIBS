#ifndef ACCOUNT_H
#define ACCOUNT_H

#define PATRON 0
#define LIBRARIAN 1
#define ADMIN 2

#include <string>

using namespace std;

class Account
{
public:
    Account();
    Account(const string& username, int accountType) : username(username), accountType(accountType) {};
    ~Account();

    const string& getAccountName() const;
    int getAccountType() const;

private:
    string username;
    int accountType;
};

#endif // ACCOUNT_H
