#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "DataOfBalance.h"

using namespace std;

class Income : public DataOfBalance {
    int incomeId;

public:
    Income(int incomeId = 0, int userId = 0, string date = "", string item = "", int amount = 0) {
        this->incomeId = incomeId;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setIncomeId(int newIncomeId);

    int getIncomeId();
};

#endif
