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

vector <User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector <User> users;
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

    return users;
}
