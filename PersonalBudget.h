#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
//#include "AdresatMenedzer.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    //AdresatMenedzer *adresatMenedzer;
    //const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    /*
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami): uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        adresatMenedzer = NULL;
    };
    */
    PersonalBudget(string fileNameWithUsers) : userManager(fileNameWithUsers) {};
    //~KsiazkaAdresowa() {
    //    delete adresatMenedzer;
    //    adresatMenedzer = NULL;
    //}
    void userRegistration();
    //void wypiszWszystkichUzytkownikow();
    void userLogging();
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
