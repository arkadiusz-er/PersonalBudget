#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"
//#include "AdresatMenedzer.h"

using namespace std;

class UserManager {
    //int idZalogowanegoUzytkownika;
    vector <User> users;

    User giveNewUserData();
    int getNewUserId();
    bool checkIfLoginExists(string login);
    FileWithUsers fileWithUsers;
public:
    //UserManager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
    //    idZalogowanegoUzytkownika = 0;
    //    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    //};
    UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
        users = fileWithUsers.loadUsersFromFile();
    };
    void userRegistration();
    //void logowanieUzytkownika();
    //void wypiszWszystkichUzytkownikow();
    //void wczytajUzytkownikowZPliku();
    //void ustawIdZalogowanegoUzytkownika(int noweId);
    //int pobierzIdZalogowanegoUzytkownika();
    //void zmianaHaslaZalogowanegoUzytkownika();
    //bool czyUzytkownikJestZalogowany();
    //void wylogowanieUzytkownika();
};

#endif
