#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"
#include "UserManager.h"
//#include "Markup.h"

using namespace std;

class FileWithExpenses : public XmlFile {
    int lastExpenseId;

public:
    FileWithExpenses(string fileNameWithExpenses) : XmlFile(fileNameWithExpenses) {
        lastExpenseId = 0;
    }
    bool addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesOfLoggedUserFromFile(int loggedUserId);
    int getLastExpenseId();
    int getLastExpenseIdFromFile();
};

#endif
