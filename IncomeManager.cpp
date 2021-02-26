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

    income.setDate(date);
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

void IncomeManager::displayIncomes() {
    system("cls");
    double sumOfIncomes = 0;
    if (!incomes.empty()) {
        cout << "                >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            displayIncomeData(*itr);
            sumOfIncomes += itr->getAmount();
        }
        cout << endl << "Sum of incomes: " << sumOfIncomes << endl;
    } else {
        cout << endl << "There isn't any item in file with incomes." << endl << endl;
    }
    system("pause");
}

void IncomeManager::displayIncomeData(Income income) {
    cout << endl << "IncomeId:  " << income.getIncomeId() << endl;
    cout << "Date:      " << income.getDate() << endl;
    cout << "Item:      " << income.getItem() << endl;
    cout << "Amount:    " << income.getAmount() << endl;
}

void IncomeManager::displayIncomesFromCurrentMonth() {
    system("cls");
    int numberOfSearchedIncomes = 0;
    double sumOfIncomes = 0;
    if (!incomes.empty()) {
        cout << "      >>> INCOMES FROM CURRENT MONTH <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (itr->getDate().substr(0,4) == AuxiliaryMethods::getCurrentYear() &&
                itr->getDate().substr(5,2) == AuxiliaryMethods::getCurrentMonth()) {
                    displayIncomeData(*itr);
                    numberOfSearchedIncomes++;
                    sumOfIncomes += itr->getAmount();
                }
        }
        cout << endl;
        displayNumberSearchedIncomes(numberOfSearchedIncomes);
        cout << "Sum of incomes: " << sumOfIncomes << endl << endl;
    } else {
        cout << endl << "There isn't any item in file with incomes." << endl << endl;
    }
    system("pause");
}

void IncomeManager::displayIncomesFromPreviousMonth() {
    system("cls");
    int numberOfSearchedIncomes = 0;
    double sumOfIncomes = 0;
    if (!incomes.empty()) {
        cout << "      >>> INCOMES FROM PREVIOUS MONTH <<<" << endl;
        cout << "-----------------------------------------------" << endl;
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
                    displayIncomeData(*itr);
                    numberOfSearchedIncomes++;
                    sumOfIncomes += itr->getAmount();
                }
        }
        cout << endl;
        displayNumberSearchedIncomes(numberOfSearchedIncomes);
        cout << "Sum of incomes: " << sumOfIncomes << endl << endl;
    } else {
        cout << endl << "There isn't any item in file with incomes." << endl << endl;
    }
    system("pause");
}

void IncomeManager::displayNumberSearchedIncomes(int numberOfSearchedIncomes) {
    if (numberOfSearchedIncomes == 0)
        cout << "There isn't any item." << endl;
    else
        cout << "Number of incomes is: " << numberOfSearchedIncomes << endl;
}

void IncomeManager::displayIncomesFromChosenPeriod() {
    system("cls");
    int numberOfSearchedIncomes = 0;
    double sumOfIncomes = 0;
    if (!incomes.empty()) {
        string firstDate = "";
        string secondDate = "";
        cout << "Type in data of begining (YYYY-MM-DD): "; cin >> firstDate;
        cout << "Type in date of ending (YYYY-MM-DD): "; cin >> secondDate;
        AuxiliaryMethods::checkIfDataIsCorrect(firstDate);
        AuxiliaryMethods::checkIfDataIsCorrect(secondDate);

        cout << endl << " >>> INCOMES FROM " << firstDate << " TO " << secondDate << " <<<" << endl;
        cout << "-----------------------------------------------" << endl;

        int firstDateAsInteger = AuxiliaryMethods::changeDateToInteger(firstDate);
        int secondDateAsInteger = AuxiliaryMethods::changeDateToInteger(secondDate);

        if (firstDateAsInteger <= secondDateAsInteger) {
            for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
                int dateFromVectorAsInteger = AuxiliaryMethods::changeDateToInteger(itr->getDate());
                if (dateFromVectorAsInteger >= firstDateAsInteger &&
                    dateFromVectorAsInteger <= secondDateAsInteger) {
                        displayIncomeData(*itr);
                        numberOfSearchedIncomes++;
                        sumOfIncomes += itr->getAmount();
                    }
            }
        cout << endl;
        displayNumberSearchedIncomes(numberOfSearchedIncomes);
        cout << "Sum of incomes: " << sumOfIncomes << endl << endl;
        } else {
            cout << endl << "There isn't any item in file with incomes." << endl << endl;
        }
    system("pause");
    }
}
