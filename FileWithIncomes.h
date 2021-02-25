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

public:
    FileWithIncomes(string fileNameWithIncomes) : XmlFile(fileNameWithIncomes) {
        lastIncomeId = 0;
    }
    bool addIncomeToFile(Income income);
    vector <Income> loadIncomesOfLoggedUserFromFile(int loggedUserId);
    int getLastIncomeId();
    int getLastIncomeIdFromFile();
};

#endif
