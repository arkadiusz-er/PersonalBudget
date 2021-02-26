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
    string date, item;
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
    amount = AuxiliaryMethods::convertStringToDouble(AuxiliaryMethods::loadLine());

    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

void ExpenseManager::displayExpenses() {
    system("cls");
    double sumOfExpenses = 0;
    cout << "                >>> EXPENSES <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    if (!expenses.empty()) {
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            displayExpenseData(*itr);
            sumOfExpenses += itr->getAmount();
        }
        cout << endl << "Sum of expenses: " << sumOfExpenses << endl;
    } else {
        cout << endl << "There isn't any item in file with expenses." << endl << endl;
    }
    system("pause");
}

void ExpenseManager::displayExpenseData(Expense expense) {
    cout << endl << "ExpenseId:  " << expense.getExpenseId() << endl;
    cout << "Date:      " << expense.getDate() << endl;
    cout << "Item:      " << expense.getItem() << endl;
    cout << "Amount:    " << expense.getAmount() << endl;
}

void ExpenseManager::displayExpensesFromCurrentMonth() {
    system("cls");
    int numberOfSearchedExpenses = 0;
    double sumOfExpenses = 0;
    cout << "      >>> EXPENSES FROM CURRENT MONTH <<<" << endl;
    cout << "-----------------------------------------------" << endl;
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
        displayNumberSearchedExpenses(numberOfSearchedExpenses);
        cout << "Sum of expenses: " << sumOfExpenses << endl << endl;
    } else {
        cout << endl << "There isn't any item in file with expenses." << endl << endl;
    }
    system("pause");
}

void ExpenseManager::displayExpensesFromPreviousMonth() {
    system("cls");
    int numberOfSearchedExpenses = 0;
    double sumOfExpenses = 0;
    cout << "      >>> EXPENSES FROM PREVIOUS MONTH <<<" << endl;
    cout << "-----------------------------------------------" << endl;
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
        displayNumberSearchedExpenses(numberOfSearchedExpenses);
        cout << "Sum of expenses: " << sumOfExpenses << endl << endl;
    } else {
        cout << endl << "There isn't any item in file with expenses." << endl << endl;
    }
    system("pause");
}

void ExpenseManager::displayNumberSearchedExpenses(int numberOfSearchedExpenses) {
    if (numberOfSearchedExpenses == 0)
        cout << "There isn't any item." << endl;
    else
        cout << "Number of expenses is: " << numberOfSearchedExpenses << endl;
}

void ExpenseManager::displayExpensesFromChosenPeriod() {
    system("cls");
    int numberOfSearchedExpenses = 0;
    double sumOfExpenses = 0;
    if (!expenses.empty()) {
        string firstDate = "";
        string secondDate = "";
        cout << "Type in data of begining (YYYY-MM-DD): "; cin >> firstDate;
        cout << "Type in date of ending (YYYY-MM-DD): "; cin >> secondDate;
        AuxiliaryMethods::checkIfDataIsCorrect(firstDate);
        AuxiliaryMethods::checkIfDataIsCorrect(secondDate);

        cout << endl << " >>> EXPENSES FROM " << firstDate << " TO " << secondDate << " <<<" << endl;
        cout << "-----------------------------------------------" << endl;

        int firstDateAsInteger = AuxiliaryMethods::changeDateToInteger(firstDate);
        int secondDateAsInteger = AuxiliaryMethods::changeDateToInteger(secondDate);

        if (firstDateAsInteger <= secondDateAsInteger) {
            for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
                int dateFromVectorAsInteger = AuxiliaryMethods::changeDateToInteger(itr->getDate());
                if (dateFromVectorAsInteger >= firstDateAsInteger &&
                    dateFromVectorAsInteger <= secondDateAsInteger) {
                        displayExpenseData(*itr);
                        numberOfSearchedExpenses++;
                        sumOfExpenses += itr->getAmount();
                    }
            }
        cout << endl;
        displayNumberSearchedExpenses(numberOfSearchedExpenses);
        cout << "Sum of expenses: " << sumOfExpenses << endl << endl;
        } else {
            cout << endl << "There isn't any item in file with expenses." << endl << endl;
        }
    system("pause");
    }
}
