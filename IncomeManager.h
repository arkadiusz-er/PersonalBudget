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
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;

    Income typeInNewIncome();
    void displayIncomeData(Income income);
    void displayNumberSearchedIncomes(int numberOfSearchedIncomes);
    //void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    //int podajIdWybranegoAdresata();
    //char wybierzOpcjeZMenuEdycja();

public:
    IncomeManager(string fileNameWithIncomes, int loggedUserId)
            : fileWithIncomes(fileNameWithIncomes), LOGGED_USER_ID(loggedUserId) {
                incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(LOGGED_USER_ID);
    };
    void addIncome();
    void displayIncomes();
    void displayIncomesFromCurrentMonth();
    void displayIncomesFromPreviousMonth();
    void displayIncomesFromChosenPeriod();
};

#endif
