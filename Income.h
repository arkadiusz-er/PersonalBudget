#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "DataOfBalance.h"

using namespace std;

class Income : public DataOfBalance {
    int incomeId;

public:
    void setIncomeId(int newIncomeId);

    int getIncomeId();
};

#endif
