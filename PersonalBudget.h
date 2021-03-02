#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses) : userManager(fileNameWithUsers),
FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {
        incomeManager = NULL;
        expenseManager = NULL;
    };
    ~PersonalBudget() {
        delete incomeManager;
        delete expenseManager;
        incomeManager = NULL;
        expenseManager = NULL;
    }
    void userRegistration();
    void userLogging();
    void addIncome();
    void addExpense();
    //int pobierzIdZalogowanegoUzytkownika();
    //void zmianaHaslaZalogowanegoUzytkownika();
    //void wylogowanieUzytkownika();
    void displayIncomes();
    void displayIncomesFromCurrentMonth();
    void displayIncomesFromPreviousMonth();
    void displayIncomesFromChosenPeriod();
    void displayExpenses();
    void displayExpensesFromCurrentMonth();
    void displayExpensesFromPreviousMonth();
    void displayExpensesFromChosenPeriod();
    //char wybierzOpcjeZMenuGlownego();
    //char wybierzOpcjeZMenuUzytkownika();
    //bool czyUzytkownikJestZalogowany();
};

#endif
