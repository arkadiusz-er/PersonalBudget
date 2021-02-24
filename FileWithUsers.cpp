#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {

    CMarkup xmlFile;
    //string liniaZDanymiUzytkownika = "";
    //xmlFile.Load(getFileName().c_str(), ios::app);
    //xmlFile.Load("users.xml");
/*
    if (plikTekstowy.good() == true) {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty() == true) {
            plikTekstowy << liniaZDanymiUzytkownika;
        } else {
            plikTekstowy << endl << liniaZDanymiUzytkownika ;
        }
    } else
        cout << "Nie udalo sie otworzyc pliku " << pobierzNazwePliku() << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
    */

    bool fileExists = xmlFile.Load( "users.xml" );

    if (!fileExists)
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("users");
    }

    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("user");
    xmlFile.IntoElem();
    xmlFile.AddElem("userId", user.getUserId());
    xmlFile.AddElem("login", user.getLogin());
    xmlFile.AddElem("password", user.getPassword());
    xmlFile.AddElem("name", user.getName());
    xmlFile.AddElem("surname", user.getSurname());

    xmlFile.Save("users.xml");

}
/*
string FileWithUsers::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik) {
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}
*/

vector <User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector <User> users;
    //string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";

    //fstream plikTekstowy;
    //plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    CMarkup xmlFile;
    xmlFile.Load("users.xml");

    //bool fileExists = xml.Load( "users.xml" );
    xmlFile.FindElem();
    while ( xmlFile.FindChildElem("user") )
    {
        xmlFile.IntoElem();
        xmlFile.FindChildElem( "userId" );
        user.setUserId(AuxiliaryMethods::convertStringToInt(xmlFile.GetChildData()));
        xmlFile.FindChildElem( "login" );
        user.setLogin(xmlFile.GetChildData());
        xmlFile.FindChildElem( "password" );
        user.setPassword(xmlFile.GetChildData());
        xmlFile.FindChildElem( "name" );
        user.setName(xmlFile.GetChildData());
        xmlFile.FindChildElem( "surname" );
        user.setSurname(xmlFile.GetChildData());
        xmlFile.OutOfElem();
        users.push_back(user);
    }

    /*
    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami)) {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }
        plikTekstowy.close();
    }
    */
    return users;
}

/*
Uzytkownik FileWithUsers::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami) {
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejUzytkownika) {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}
*/
/*
void FileWithUsers::zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy) {
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    vector <Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out);

    if (plikTekstowy.good() == true) {
        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec) {
                plikTekstowy << liniaZDanymiUzytkownika;
            } else {
                plikTekstowy << liniaZDanymiUzytkownika << endl;
            }
            liniaZDanymiUzytkownika = "";
        }
    } else {
        cout << "Nie mozna otworzyc pliku " << pobierzNazwePliku() << endl;
    }
    plikTekstowy.close();
}
*/
