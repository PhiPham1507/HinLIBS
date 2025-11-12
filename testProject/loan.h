#ifndef LOAN_H
#define LOAN_H

#include "date.h"
#include "item.h"

class Loan
{
    public:
        Loan();
        Loan(Item*, Date, Date);


   private:

        Item* item;
        Date loanIssueDate, loanDueDate;
};

#endif // LOAN_H
