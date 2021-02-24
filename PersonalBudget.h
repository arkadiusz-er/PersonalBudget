#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    //AdresatMenedzer *adresatMenedzer;
    IncomeManager *incomeManager;
    const string FILE_NAME_WITH_INCOMES;

public:
    /*
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami): uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        adresatMenedzer = NULL;
    };
    */
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes) : userManager(fileNameWithUsers),
FILE_NAME_WITH_INCOMES(fileNameWithIncomes) {
        incomeManager = NULL;
    };
    //~KsiazkaAdresowa() {
    //    delete adresatMenedzer;
    //    adresatMenedzer = NULL;
    //}
    ~PersonalBudget() {
        delete incomeManager;
        incomeManager = NULL;
    }
    void userRegistration();
    //void wypiszWszystkichUzytkownikow();
    void userLogging();
    void addIncome();
    //int pobierzIdZalogowanegoUzytkownika();
    //void zmianaHaslaZalogowanegoUzytkownika();
    //void wylogowanieUzytkownika();
    //void wyswietlWszystkichAdresatow();
    //void wyszukajAdresatowPoImieniu();
    //void wyszukajAdresatowPoNazwisku();
    //char wybierzOpcjeZMenuGlownego();
    //char wybierzOpcjeZMenuUzytkownika();
    //bool czyUzytkownikJestZalogowany();
};

#endif
