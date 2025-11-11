#ifndef LOAN_H
#define LOAN_H

#include "date.h"
#include "item.h"

class Loan
{
    public:
        Loan();

   private:

        Item* item;
        Date loanIssueDate, loanDueDate;
};

#endif // LOAN_H
