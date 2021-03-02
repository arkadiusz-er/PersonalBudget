#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Income.h"
#include "FileWithIncomes.h"

using namespace std;

class IncomeManager {
    const int LOGGED_USER_ID;
    double sumOfIncomes;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;

    Income typeInNewIncome();
    void displayIncomeData(Income income);
    void displayNumberSearchedIncomes(int numberOfSearchedIncomes);

public:
    IncomeManager(string fileNameWithIncomes, int loggedUserId)
            : fileWithIncomes(fileNameWithIncomes), LOGGED_USER_ID(loggedUserId) {
                incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(LOGGED_USER_ID);
                sumOfIncomes = 0;
    };
    void addIncome();
    void displayIncomes();
    void displayIncomesFromCurrentMonth();
    void displayIncomesFromPreviousMonth();
    void displayIncomesFromChosenPeriod(int firstDate, int secondDate);

    void setSumOfIncomes(double newSumOfIncomes);
    double getSumOfIncomes();
};

#endif
