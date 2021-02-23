#include "FileWithIncomes.h"

bool FileWithIncomes::addIncomeToFile(Income income) {
    //string liniaZDanymiAdresata = "";
    //fstream plikTekstowy;
    //plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);
    CMarkup xmlFile;
    //xmlFile.Load("incomes.xml");

    bool fileExists = xmlFile.Load( "incomes.xml" );

    if (!fileExists)
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("incomes");
    }

    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("income");
    xmlFile.IntoElem();
    xmlFile.AddElem("incomeId", income.getIncomeId());
    xmlFile.AddElem("userId", income.getUserId());
    xmlFile.AddElem("date", income.getDate());
    xmlFile.AddElem("item", income.getItem());
    xmlFile.AddElem("amount", income.getAmount());

    xmlFile.Save("incomes.xml");
    lastIncomeId++;
    return true;
    /*
    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    */
    //return false;
}

int FileWithIncomes::getLastIncomeId() {
    return lastIncomeId;
}

int FileWithIncomes::getLastIncomeIdFromFile() {
    CMarkup xmlFile;
    //plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    xmlFile.Load("incomes.xml");
    xmlFile.FindElem();
    while (xmlFile.FindChildElem("income")) {
        xmlFile.IntoElem();
        xmlFile.FindChildElem( "incomeId" );
        lastIncomeId = AuxiliaryMethods::convertStringToInt(xmlFile.GetChildData());
    }
    /*
    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    */
    return lastIncomeId;
}
