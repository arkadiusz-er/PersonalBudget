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
    double sumOfExpenses;
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;

    Expense typeInNewExpense();
    void displayExpenseData(Expense expense);
    void displayNumberSearchedExpenses(int numberOfSearchedExpenses);
    static bool compareDates(Expense &date1, Expense &date2);

public:
    ExpenseManager(string fileNameWithExpenses, int loggedUserId)
            : fileWithExpenses(fileNameWithExpenses), LOGGED_USER_ID(loggedUserId) {
                expenses = fileWithExpenses.loadExpensesOfLoggedUserFromFile(LOGGED_USER_ID);
                sumOfExpenses = 0;
    };
    void addExpense();
    void displayExpenses();
    void displayExpensesFromCurrentMonth();
    void displayExpensesFromPreviousMonth();
    void displayExpensesFromChosenPeriod(int firstDate, int secondDate);

    void setSumOfExpenses(double newSumOfExpenses);
    double getSumOfExpenses();
};

#endif
