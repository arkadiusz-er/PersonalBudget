#include "IncomeManager.h"

void IncomeManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> Adding a new income <<<" << endl << endl;
    income = typeInNewIncome();

    incomes.push_back(income);
    if (fileWithIncomes.addIncomeToFile(income))
        cout << "Income has been added" << endl;
    else
        cout << "Error. Income has not been added." << endl;
    system("pause");

}

Income IncomeManager::typeInNewIncome() {
    Income income;
    string date, item;
    int amount;

    income.setIncomeId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_USER_ID);

    cout << "Type in a date: ";
    date = AuxiliaryMethods::loadLine();

    cout << "Type in an item: ";
    item = AuxiliaryMethods::loadLine();
    item = AuxiliaryMethods::replaceFirstLetterToCapitalRestToLower(item);

    cout << "Type in an amount: ";
    amount = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::loadLine());

    income.setDate(date);
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

void IncomeManager::displayIncomes() {
    system("cls");
    if (!incomes.empty()) {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            displayIncomeData(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "There isn't any item in file with incomes." << endl << endl;
    }
    system("pause");
}

void IncomeManager::displayIncomeData(Income income) {
    cout << endl << "IncomeId:                 " << income.getIncomeId() << endl;
    cout << "Date:               " << income.getDate() << endl;
    cout << "Item:           " << income.getItem() << endl;
    cout << "Amount:     " << income.getAmount() << endl;
}
