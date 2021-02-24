#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"
#include "UserManager.h"
//#include "Markup.h"

using namespace std;

class FileWithIncomes : public XmlFile {
    int lastIncomeId;

    //string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    //string pobierzLiczbe(string tekst, int pozycjaZnaku);
    //Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    //int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    //int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
public:
    FileWithIncomes(string fileNameWithIncomes) : XmlFile(fileNameWithIncomes) {
        lastIncomeId = 0;
    }
    bool addIncomeToFile(Income income);
    //bool usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
    //void edytujAdresataWPliku(Adresat adresat, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    vector <Income> loadIncomesOfLoggedUserFromFile(int loggedUserId);
    int getLastIncomeId();
    //void podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);
    int getLastIncomeIdFromFile();
};

#endif
