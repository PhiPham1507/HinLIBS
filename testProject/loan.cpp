#include "loan.h"

Loan::Loan(Item* item, Date issue, Date due) : item(item), loanIssueDate(issue), loanDueDate(due)
{


}
Loan::Loan(){

}

string Loan::display()
{
    return item->display() + "\tDue date: " + loanDueDate.getString();
}
