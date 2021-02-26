#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "DataOfBalance.h"

using namespace std;

class Expense : public DataOfBalance {
    int expenseId;

public:
    Expense(int expenseId = 0, int userId = 0, string date = "", string item = "", double amount = 0) {
        this->expenseId = expenseId;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setExpenseId(int newExpenseId);

    int getExpenseId();
};

#endif
