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
    Account(const string& username, const string& password);
    virtual ~Account();

    const string& getAccountName() const;
    const string& getPassword() const;
    virtual int getAccountType() const = 0;

protected:
    string username;
    string password;
    int accountType;
};

#endif // ACCOUNT_H
