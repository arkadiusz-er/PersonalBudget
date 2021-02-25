#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    IncomeManager *incomeManager;
    const string FILE_NAME_WITH_INCOMES;

public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes) : userManager(fileNameWithUsers),
FILE_NAME_WITH_INCOMES(fileNameWithIncomes) {
        incomeManager = NULL;
    };
    ~PersonalBudget() {
        delete incomeManager;
        incomeManager = NULL;
    }
    void userRegistration();
    void userLogging();
    void addIncome();
    //int pobierzIdZalogowanegoUzytkownika();
    //void zmianaHaslaZalogowanegoUzytkownika();
    //void wylogowanieUzytkownika();
    void displayIncomes();
    void displayIncomesFromCurrentMonth();
    void displayIncomesFromPreviousMonth();
    void displayIncomesFromChosenPeriod();
    //char wybierzOpcjeZMenuGlownego();
    //char wybierzOpcjeZMenuUzytkownika();
    //bool czyUzytkownikJestZalogowany();
};

#endif
