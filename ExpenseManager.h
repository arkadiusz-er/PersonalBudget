#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Expense.h"
#include "FileWithExpenses.h"

using namespace std;

class ExpenseManager {
    const int LOGGED_USER_ID;
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;

    Expense typeInNewExpense();
    void displayExpenseData(Expense expense);
    void displayNumberSearchedExpenses(int numberOfSearchedExpenses);

public:
    ExpenseManager(string fileNameWithExpenses, int loggedUserId)
            : fileWithExpenses(fileNameWithExpenses), LOGGED_USER_ID(loggedUserId) {
                expenses = fileWithExpenses.loadExpensesOfLoggedUserFromFile(LOGGED_USER_ID);
    };
    void addExpense();
    void displayExpenses();
    void displayExpensesFromCurrentMonth();
    void displayExpensesFromPreviousMonth();
    void displayExpensesFromChosenPeriod();
};

#endif
