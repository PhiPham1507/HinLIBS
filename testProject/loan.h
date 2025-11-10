#ifndef LOAN_H
#define LOAN_H

#include "date.h"

class Loan
{
    public:
        Loan();
        Loan(Date date);

   private:
        Date date;
};

#endif // LOAN_H
