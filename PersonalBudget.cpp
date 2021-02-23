#include "PersonalBudget.h"

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

void PersonalBudget::userLogging() {
    userManager.userLogging();
    if (userManager.checkIfUserIsLogged()) {
        incomeManager = new IncomeManager(FILE_NAME_WITH_INCOMES, userManager.getLoggedUserId());
    }
}
/*
void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}
*/
void PersonalBudget::addIncome() {
    //if (UserManager.checkIfUserIsLogged()) {
        incomeManager->addIncome();
    //} else {
    //    cout << "Aby dodac adresata nalezy najpierw sie zalogowac!" << endl;
    //    system("pause");
    //}
}
