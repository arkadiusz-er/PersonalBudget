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
/*
void PersonalBudget::displayIncomesFromChosenPeriod() {
    if (userManager.checkIfUserIsLogged()) {
        incomeManager->displayIncomesFromChosenPeriod();
    }
}
*/
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
/*
void PersonalBudget::displayExpensesFromChosenPeriod() {
    if (userManager.checkIfUserIsLogged()) {
        expenseManager->displayExpensesFromChosenPeriod();
    }
}
*/
void PersonalBudget::displayBalanceFromCurrentMonth() {
    if (userManager.checkIfUserIsLogged()) {
        system("cls");
        cout << "      >>> BALANCE FROM CURRENT MONTH <<<" << endl;
        cout << "------------------------------------------------" << endl;
        incomeManager->displayIncomesFromCurrentMonth();
        expenseManager->displayExpensesFromCurrentMonth();
        cout << "-----------------------------" << endl;
        cout << "Sum of incomes is: " << incomeManager->getSumOfIncomes() << endl;
        cout << "Sum of expenses is: " << expenseManager->getSumOfExpenses() << endl;
        cout << "Balance is: " << (incomeManager->getSumOfIncomes()) - (expenseManager->getSumOfExpenses()) << endl;
        cout << "-----------------------------" << endl;
    }
}

void PersonalBudget::displayBalanceFromPreviousMonth() {
    if (userManager.checkIfUserIsLogged()) {
        system("cls");
        cout << "      >>> BALANCE FROM PREVIOUS MONTH <<<" << endl;
        cout << "------------------------------------------------" << endl;
        incomeManager->displayIncomesFromPreviousMonth();
        expenseManager->displayExpensesFromPreviousMonth();
        cout << "-----------------------------" << endl;
        cout << "Sum of incomes is: " << incomeManager->getSumOfIncomes() << endl;
        cout << "Sum of expenses is: " << expenseManager->getSumOfExpenses() << endl;
        cout << "Balance is: " << (incomeManager->getSumOfIncomes()) - (expenseManager->getSumOfExpenses()) << endl;
        cout << "-----------------------------" << endl;
    }
}

void PersonalBudget::displayBalanceFromChosenPeriod() {
    if (userManager.checkIfUserIsLogged()) {
        system("cls");
        string firstDate = "";
        string secondDate = "";
        cout << "Type in date of begining (YYYY-MM-DD): "; cin >> firstDate;
        while (AuxiliaryMethods::checkIfDataIsCorrect(firstDate) == false) {
            cout << "Type in date of beginning (YYYY-MM-DD): "; cin >> firstDate;
        }
        int firstDateAsInteger = AuxiliaryMethods::changeDateToInteger(firstDate);
        cout << "Type in date of ending (YYYY-MM-DD): "; cin >> secondDate;
        while (AuxiliaryMethods::checkIfDataIsCorrect(secondDate) == false) {
            cout << "Type in date of ending (YYYY-MM-DD): "; cin >> secondDate;
        }
        int secondDateAsInteger = AuxiliaryMethods::changeDateToInteger(secondDate);
        while (firstDateAsInteger > secondDateAsInteger) {
            cout << "Date of ending is incorrect - it cannot be before date of beginning." << endl << endl;
            cout << "Type in date of ending (YYYY-MM-DD): "; cin >> secondDate;
            secondDateAsInteger = AuxiliaryMethods::changeDateToInteger(secondDate);
        }
        system("cls");
        cout << "      >>> BALANCE FROM " << firstDate << " TO " << secondDate << " <<<" << endl;
        cout << "---------------------------------------------------------" << endl;

        incomeManager->displayIncomesFromChosenPeriod(firstDateAsInteger, secondDateAsInteger);
        expenseManager->displayExpensesFromChosenPeriod(firstDateAsInteger, secondDateAsInteger);
        cout << "-----------------------------" << endl;
        cout << "Sum of incomes is: " << incomeManager->getSumOfIncomes() << endl;
        cout << "Sum of expenses is: " << expenseManager->getSumOfExpenses() << endl;
        cout << "Balance is: " << (incomeManager->getSumOfIncomes()) - (expenseManager->getSumOfExpenses()) << endl;
        cout << "-----------------------------" << endl;

    }
}
