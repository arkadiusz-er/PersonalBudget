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
    string date, item, amountStr;
    double amount;

    income.setIncomeId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_USER_ID);

    char userReply;
    cout << "Does income concern today? (y/n) ";
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
        while (AuxiliaryMethods::checkIfDateIsCorrect(date) == false) {
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

    income.setDate(date);
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

void IncomeManager::displayIncomes() {
    system("cls");
    sumOfIncomes = 0;
    cout << "                >>> INCOMES <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    if (!incomes.empty()) {
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            displayIncomeData(*itr);
            sumOfIncomes += itr->getAmount();
        }
    } else {
        cout << endl << "There isn't any item in file with incomes." << endl << endl;
    }
    system("pause");
}

void IncomeManager::displayIncomeData(Income income) {
    //cout << endl << "IncomeId:  " << income.getIncomeId() << endl;
    cout << endl << "Date:      " << income.getDate() << endl;
    cout << "Item:      " << income.getItem() << endl;
    cout << "Amount:    " << income.getAmount() << endl;
}

void IncomeManager::displayIncomesFromCurrentMonth() {

    int numberOfSearchedIncomes = 0;
    sumOfIncomes = 0;
    cout << "     INCOMES     " << endl;
    cout << "-----------------------------------" << endl;
    if (!incomes.empty()) {
        vector <Income> sortedIncomes;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (itr->getDate().substr(0,4) == AuxiliaryMethods::getCurrentYear() &&
                itr->getDate().substr(5,2) == AuxiliaryMethods::getCurrentMonth()) {
                    sortedIncomes.push_back(*itr);
                }
        }
        if (!sortedIncomes.empty()) {
            sort(sortedIncomes.begin(), sortedIncomes.end(), compareDates);
            for (vector <Income> :: iterator itr2 = sortedIncomes.begin(); itr2 != sortedIncomes.end(); itr2++) {
                displayIncomeData(*itr2);
                sumOfIncomes += itr2->getAmount();
            }
            cout << endl;
        } else {
            if (sumOfIncomes == 0) cout << "In this period there isn't any item."  << endl << endl;
        }
    } else {
        cout << endl << "There isn't any item in file with incomes." << endl << endl;
    }
}

void IncomeManager::displayIncomesFromPreviousMonth() {
    int numberOfSearchedIncomes = 0;
    sumOfIncomes = 0;
    cout << "     INCOMES     " << endl;
    cout << "-----------------------------------" << endl;
    if (!incomes.empty()) {
        vector <Income> sortedIncomes;
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
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (itr->getDate().substr(0,4) == searchedYearString &&
                itr->getDate().substr(5,2) == searchedMonthString) {
                    sortedIncomes.push_back(*itr);
                }
        }
        if (!sortedIncomes.empty()) {
            sort(sortedIncomes.begin(), sortedIncomes.end(), compareDates);
            for (vector <Income> :: iterator itr2 = sortedIncomes.begin(); itr2 != sortedIncomes.end(); itr2++) {
                displayIncomeData(*itr2);
                sumOfIncomes += itr2->getAmount();
            }
            cout << endl;
        } else {
            if (sumOfIncomes == 0) cout << "In this period there isn't any item."  << endl << endl;
        }
    } else {
        cout << endl << "There isn't any item in file with incomes." << endl << endl;
    }
}

void IncomeManager::displayNumberSearchedIncomes(int numberOfSearchedIncomes) {
    if (numberOfSearchedIncomes == 0)
        cout << "There isn't any item." << endl;
    else
        cout << "Number of incomes is: " << numberOfSearchedIncomes << endl;
}

void IncomeManager::displayIncomesFromChosenPeriod(int firstDate, int secondDate) {
    int numberOfSearchedIncomes = 0;
    sumOfIncomes = 0;
    if (!incomes.empty()) {
        vector <Income> sortedIncomes;
        cout << "     INCOMES     " << endl;
        cout << "-----------------------------------" << endl;

        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            int dateFromVectorAsInteger = AuxiliaryMethods::changeDateToInteger(itr->getDate());
            if (dateFromVectorAsInteger >= firstDate &&
                dateFromVectorAsInteger <= secondDate) {
                    sortedIncomes.push_back(*itr);
                }
        }
        if (!sortedIncomes.empty()) {
            sort(sortedIncomes.begin(), sortedIncomes.end(), compareDates);
            for (vector <Income> :: iterator itr2 = sortedIncomes.begin(); itr2 != sortedIncomes.end(); itr2++) {
                displayIncomeData(*itr2);
                sumOfIncomes += itr2->getAmount();
            }
            cout << endl;
        } else {
            if (sumOfIncomes == 0) cout << "In this period there isn't any item."  << endl << endl;
        }
    } else {
        cout << endl << "There isn't any item in file with incomes." << endl << endl;
    }
}


void IncomeManager::setSumOfIncomes(double newSumOfIncomes) {
    if (newSumOfIncomes >= 0) sumOfIncomes = newSumOfIncomes;
}

double IncomeManager::getSumOfIncomes() {
    return sumOfIncomes;
}

bool IncomeManager::compareDates(Income &date1, Income &date2) {
    return AuxiliaryMethods::changeDateToInteger(date1.getDate()) < AuxiliaryMethods::changeDateToInteger(date2.getDate());
}
