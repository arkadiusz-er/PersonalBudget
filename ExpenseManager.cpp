#include "ExpenseManager.h"

void ExpenseManager::addExpense() {
    Expense expense;

    system("cls");
    cout << " >>> Adding a new expense <<<" << endl << endl;
    expense = typeInNewExpense();

    expenses.push_back(expense);
    if (fileWithExpenses.addExpenseToFile(expense))
        cout << "Expense has been added" << endl;
    else
        cout << "Error. Expense has not been added." << endl;
    system("pause");

}

Expense ExpenseManager::typeInNewExpense() {
    Expense expense;
    string date, item, amountStr;
    double amount;

    expense.setExpenseId(fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_USER_ID);

    char userReply;
    cout << "Does expense concern today? (y/n) ";
    cin >> userReply;
    while (userReply != 'Y' && userReply != 'N') {
        cout << "Incorrect sign. Please choose from Y or N. ";
        cin >> userReply;
        cout << endl;
    }
    if (userReply == 'Y') {
        date = AuxiliaryMethods::getTodaysDate();
    } else if (userReply == 'N') {
        cout << "Type in a date (YYYY-MM-DD): ";
        date = AuxiliaryMethods::loadLine();
        while (AuxiliaryMethods::checkIfDataIsCorrect(date) == false) {
            cout << "Type in a date (YYYY-MM-DD): ";
            date = AuxiliaryMethods::loadLine();
        }
    }

    cout << "Type in an item: ";
    item = AuxiliaryMethods::loadLine();
    item = AuxiliaryMethods::replaceFirstLetterToCapitalRestToLower(item);

    cout << "Type in an amount: ";
    amountStr = AuxiliaryMethods::loadLine();
    amountStr = AuxiliaryMethods::changeCommaIfExistsToDot(amountStr);
    amount = AuxiliaryMethods::convertStringToDouble(amountStr);

    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

void ExpenseManager::displayExpenses() {
    system("cls");
    sumOfExpenses = 0;
    cout << "                >>> EXPENSES <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    if (!expenses.empty()) {
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            displayExpenseData(*itr);
            sumOfExpenses += itr->getAmount();
        }
    } else {
        cout << endl << "There isn't any item in file with expenses." << endl << endl;
    }
    system("pause");
}

void ExpenseManager::displayExpenseData(Expense expense) {
    //cout << endl << "ExpenseId:  " << expense.getExpenseId() << endl;
    cout << endl << "Date:      " << expense.getDate() << endl;
    cout << "Item:      " << expense.getItem() << endl;
    cout << "Amount:    " << expense.getAmount() << endl;
}

void ExpenseManager::displayExpensesFromCurrentMonth() {
    int numberOfSearchedExpenses = 0;
    sumOfExpenses = 0;
    cout << "     EXPENSES     " << endl;
    cout << "------------------" << endl;
    if (!expenses.empty()) {
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            if (itr->getDate().substr(0,4) == AuxiliaryMethods::getCurrentYear() &&
                itr->getDate().substr(5,2) == AuxiliaryMethods::getCurrentMonth()) {
                    displayExpenseData(*itr);
                    numberOfSearchedExpenses++;
                    sumOfExpenses += itr->getAmount();
                }
        }
        cout << endl;
    } else {
        cout << endl << "There isn't any item in file with expenses." << endl << endl;
    }
}

void ExpenseManager::displayExpensesFromPreviousMonth() {
    int numberOfSearchedExpenses = 0;
    sumOfExpenses = 0;
    cout << "     EXPENSES     " << endl;
    cout << "------------------" << endl;
    if (!expenses.empty()) {
        int searchedMonthInt = 0;
        int searchedYearInt = 0;
        string today = AuxiliaryMethods::getTodaysDate();
        if (today.substr(5,2) == "01") {
            searchedMonthInt = 12;
            searchedYearInt = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::getCurrentYear()) - 1;
        } else {
            searchedMonthInt = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::getCurrentMonth()) - 1;
            searchedYearInt = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::getCurrentYear());
        }
        string searchedYearString = AuxiliaryMethods::convertIntToString(searchedYearInt);
        string searchedMonthString = AuxiliaryMethods::checkIfOneSignInDate(AuxiliaryMethods::convertIntToString(searchedMonthInt));
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            if (itr->getDate().substr(0,4) == searchedYearString &&
                itr->getDate().substr(5,2) == searchedMonthString) {
                    displayExpenseData(*itr);
                    numberOfSearchedExpenses++;
                    sumOfExpenses += itr->getAmount();
                }
        }
        cout << endl;
    } else {
        cout << endl << "There isn't any item in file with expenses." << endl << endl;
    }
}

void ExpenseManager::displayNumberSearchedExpenses(int numberOfSearchedExpenses) {
    if (numberOfSearchedExpenses == 0)
        cout << "There isn't any item." << endl;
    else
        cout << "Number of expenses is: " << numberOfSearchedExpenses << endl;
}

void ExpenseManager::displayExpensesFromChosenPeriod(int firstDate, int secondDate) {
    //system("cls");
    int numberOfSearchedExpenses = 0;
    sumOfExpenses = 0;
    if (!expenses.empty()) {

        cout << "     EXPENSES     " << endl;
        cout << "------------------" << endl;

        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            int dateFromVectorAsInteger = AuxiliaryMethods::changeDateToInteger(itr->getDate());
            if (dateFromVectorAsInteger >= firstDate &&
                dateFromVectorAsInteger <= secondDate) {
                    displayExpenseData(*itr);
                    numberOfSearchedExpenses++;
                    sumOfExpenses += itr->getAmount();
                }
            }
        cout << endl;
    } else {
        cout << endl << "There isn't any item in file with expenses." << endl << endl;
    }
}


void ExpenseManager::setSumOfExpenses(double newSumOfExpenses) {
    if (newSumOfExpenses >= 0) sumOfExpenses = newSumOfExpenses;
}

double ExpenseManager::getSumOfExpenses() {
    return sumOfExpenses;
}
