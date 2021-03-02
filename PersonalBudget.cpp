#include "PersonalBudget.h"

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

void PersonalBudget::userLogging() {
    userManager.userLogging();
    if (userManager.checkIfUserIsLogged()) {
        incomeManager = new IncomeManager(FILE_NAME_WITH_INCOMES, userManager.getLoggedUserId());
        expenseManager = new ExpenseManager(FILE_NAME_WITH_EXPENSES, userManager.getLoggedUserId());
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

void PersonalBudget::addExpense() {
    if (userManager.checkIfUserIsLogged()) {
        expenseManager->addExpense();
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

void PersonalBudget::displayExpenses() {
    if (userManager.checkIfUserIsLogged()) {
        expenseManager->displayExpenses();
    }
}

void PersonalBudget::displayExpensesFromCurrentMonth() {
    if (userManager.checkIfUserIsLogged()) {
        expenseManager->displayExpensesFromCurrentMonth();
    }
}

void PersonalBudget::displayExpensesFromPreviousMonth() {
    if (userManager.checkIfUserIsLogged()) {
        expenseManager->displayExpensesFromPreviousMonth();
    }
}

void PersonalBudget::displayExpensesFromChosenPeriod() {
    if (userManager.checkIfUserIsLogged()) {
        expenseManager->displayExpensesFromChosenPeriod();
    }
}
