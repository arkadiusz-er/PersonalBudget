#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {
public:
    static string convertIntToString(int number);
    static string loadLine();
    static string replaceFirstLetterToCapitalRestToLower(string text);
    static int convertStringToInt(string number);
    //static char wczytajZnak();
    //static int wczytajLiczbeCalkowita();
    //static void usunPlik(string nazwaPlikuZRozszerzeniem);
    //static void zmienNazwePliku(string staraNazwa, string nowaNazwa);
};

#endif
