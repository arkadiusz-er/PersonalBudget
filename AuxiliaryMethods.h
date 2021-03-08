#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <windows.h>

using namespace std;

class AuxiliaryMethods {
public:
    static string convertIntToString(int number);
    static string convertDoubleToString(double number);
    static char loadSign();
    static string loadLine();
    static string replaceFirstLetterToCapitalRestToLower(string text);
    static int convertStringToInt(string number);
    static double convertStringToDouble(string number);

    static string getTodaysDate();
    static string getCurrentYear();
    static string getCurrentMonth();
    static string getCurrentDay();
    static string checkIfOneSignInDate(string x);
    static bool checkIfDateIsCorrect (string dateToChecking);

    static int changeDateToInteger (string dataToChange);
    static string changeIntegerToDate(int dateAsInteger);
    static string changeCommaIfExistsToDot(string amountString);
    static char replaceToCapitalLetter(char letter);
};

#endif
