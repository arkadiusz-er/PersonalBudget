#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number) {
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
