#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Income.h"
#include "FileWithIncomes.h"

using namespace std;

class IncomeManager {
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;

    Income typeInNewIncome();
    //void wyswietlDaneAdresata(Adresat adresat);
    //void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    //int podajIdWybranegoAdresata();
    //char wybierzOpcjeZMenuEdycja();

public:
    //AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
    //    : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
    //        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    //    };
    IncomeManager(string fileNameWithIncomes, int loggedUserId)
            : fileWithIncomes(fileNameWithIncomes), LOGGED_USER_ID(loggedUserId) {
                incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(LOGGED_USER_ID);
    };
    void addIncome();
    //void wyswietlWszystkichAdresatow();
    //void wyszukajAdresatowPoImieniu();
    //void wyszukajAdresatowPoNazwisku();
    //void usunAdresata();
    //void edytujAdresata();
    //void zaktualizujDaneWybranegoAdresata(Adresat adresat);
    //string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);


};

#endif
