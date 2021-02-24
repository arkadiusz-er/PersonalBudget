#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "DataOfBalance.h"

using namespace std;

class Expense : public DataOfBalance {
    int expenseId;

public:
    void setExpenseId(int newExpenseId);

    int getExpenseId();
};

#endif
