#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
//#include "MetodyPomocnicze.h"
#include "XmlFile.h"

using namespace std;

class FileWithUsers : public XmlFile {
    //string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    //Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    FileWithUsers(string fileNameWithUsers) : XmlFile(fileNameWithUsers) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);
};

#endif
