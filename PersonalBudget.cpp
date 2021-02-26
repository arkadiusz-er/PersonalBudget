#include "PersonalBudget.h"

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

void PersonalBudget::userLogging() {
    userManager.userLogging();
    if (userManager.checkIfUserIsLogged()) {
        incomeManager = new IncomeManager(FILE_NAME_WITH_INCOMES, userManager.getLoggedUserId());
    }
}

void PersonalBudget::addIncome() {
    if (userManager.checkIfUserIsLogged()) {
        incomeManager->addIncome();
    } else {
        cout << "You have to login firstly!" << endl;
        system("pause");
    }
}

void PersonalBudget::displayIncomes() {
    if (userManager.checkIfUserIsLogged()) {
        incomeManager->displayIncomes();
    }
}

void PersonalBudget::displayIncomesFromCurrentMonth() {
    if (userManager.checkIfUserIsLogged()) {
        incomeManager->displayIncomesFromCurrentMonth();
    }
}

void PersonalBudget::displayIncomesFromPreviousMonth() {
    if (userManager.checkIfUserIsLogged()) {
        incomeManager->displayIncomesFromPreviousMonth();
    }
}

void PersonalBudget::displayIncomesFromChosenPeriod() {
    if (userManager.checkIfUserIsLogged()) {
        incomeManager->displayIncomesFromChosenPeriod();
    }
}
