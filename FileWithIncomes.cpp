#include "FileWithIncomes.h"

bool FileWithIncomes::addIncomeToFile(Income income) {
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(getFileName());

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
    xmlFile.AddElem("amount", AuxiliaryMethods::convertDoubleToString(income.getAmount()));

    xmlFile.Save(getFileName());
    lastIncomeId++;
    return true;
}

int FileWithIncomes::getLastIncomeId() {
    return lastIncomeId;
}

int FileWithIncomes::getLastIncomeIdFromFile() {
    CMarkup xmlFile;
    xmlFile.Load(getFileName());
    xmlFile.FindElem();
    while (xmlFile.FindChildElem("income")) {
        xmlFile.IntoElem();
        xmlFile.FindChildElem( "incomeId" );
        lastIncomeId = AuxiliaryMethods::convertStringToInt(xmlFile.GetChildData());
    }
    return lastIncomeId;
}

vector <Income> FileWithIncomes::loadIncomesOfLoggedUserFromFile(int loggedUserId) {
    vector <Income> incomes;
    Income income;
    CMarkup xmlFile;
    xmlFile.Load(getFileName());
    while (xmlFile.FindChildElem("income")) {
        xmlFile.IntoElem();
        xmlFile.FindChildElem( "incomeId" );
        income.setIncomeId(AuxiliaryMethods::convertStringToInt(xmlFile.GetChildData()));
        lastIncomeId = income.getIncomeId();
        xmlFile.FindChildElem( "userId" );
        if (loggedUserId == AuxiliaryMethods::convertStringToInt(xmlFile.GetChildData())) {
            income.setUserId(loggedUserId);
            xmlFile.FindChildElem( "date" );
            income.setDate(xmlFile.GetChildData());
            xmlFile.FindChildElem( "item" );
            income.setItem(xmlFile.GetChildData());
            xmlFile.FindChildElem( "amount" );
            income.setAmount(AuxiliaryMethods::convertStringToDouble(xmlFile.GetChildData()));
            incomes.push_back(income);
        }
        xmlFile.OutOfElem();
    }
    return incomes;
}
