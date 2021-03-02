#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertDoubleToString(double number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

double AuxiliaryMethods::convertStringToDouble(string number) {
    double numberDouble;
    istringstream iss(number);
    iss >> numberDouble;

    return numberDouble;
}

string AuxiliaryMethods::loadLine() {
    string enteredData = "";
    cin.sync();
    getline(cin, enteredData);
    return enteredData;
}

string AuxiliaryMethods::replaceFirstLetterToCapitalRestToLower(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AuxiliaryMethods::getTodaysDate() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    string dayOfToday = checkIfOneSignInDate(convertIntToString(st.wDay));
    string monthOfToday = checkIfOneSignInDate(convertIntToString(st.wMonth));
    string yearOfToday = convertIntToString(st.wYear);
    string today = yearOfToday + "-" + monthOfToday + "-" + dayOfToday;
    return today;
}

string AuxiliaryMethods::getCurrentYear() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    string yearOfToday = convertIntToString(st.wYear);
    return yearOfToday;
}

string AuxiliaryMethods::getCurrentMonth() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    string monthOfToday = checkIfOneSignInDate(convertIntToString(st.wMonth));
    return monthOfToday;
}

string AuxiliaryMethods::getCurrentDay() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    string dayOfToday = checkIfOneSignInDate(convertIntToString(st.wDay));
    return dayOfToday;
}

string AuxiliaryMethods::checkIfOneSignInDate(string x) {
    if (x.length() == 1) {
        x += "0";
        char temp = x[0];
        x = x[1];
        x += temp;
    }
    return x;
}

bool AuxiliaryMethods::checkIfDataIsCorrect (string dateToChecking) {
    SYSTEMTIME st;
    GetSystemTime(&st);

    if (dateToChecking[4] == '-' && dateToChecking[7] == '-' && dateToChecking.length() == 10) {
        int year = AuxiliaryMethods::convertStringToInt(dateToChecking.substr(0,4));
        int month = AuxiliaryMethods::convertStringToInt(dateToChecking.substr(5,2));
        int day = AuxiliaryMethods::convertStringToInt(dateToChecking.substr(8,2));
        if (year >= 2000 && year < st.wYear && month <= 12 && day <= 31 || (year == st.wYear && month == st.wMonth && day <= st.wDay) || (year == st.wYear && month < st.wMonth && day <= 31)) {
            if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
                cout << "This month has 30 days.";
            } else if (year % 4 == 0 && month == 2 && day > 29) {
                cout << "This month has 29 days.";
            } else if (year % 4 != 0 && month == 2 && day > 28) {
                cout << "This month has 28 days.";
            } else {
                return true;
            }
        } else {
            cout << "This date is incorrect.";
        }
    } else
        cout << "Incorrect format of data.";
    cout << endl << endl;
    return false;
}

int AuxiliaryMethods::changeDateToInteger (string dataToChange) {
    dataToChange = dataToChange.substr(0,4) + dataToChange.substr(5,2) + dataToChange.substr(8,2);
    int dateAsInteger = convertStringToInt(dataToChange);
    return dateAsInteger;
}

string AuxiliaryMethods::changeIntegerToDate(int dateAsInteger) {
    string data = convertIntToString(dateAsInteger);
    data = data.substr(0,4) + "-" + data.substr(4,2) + "-" + data.substr(6,2);
    return data;
}

string AuxiliaryMethods::changeCommaIfExistsToDot(string amountString) {
    for (int i = 0; i < amountString.length(); i++) {
        if (amountString[i] == 44) amountString[i] = 46;
    }
    return amountString;
}
