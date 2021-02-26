#include "FileWithExpenses.h"

bool FileWithExpenses::addExpenseToFile(Expense expense) {
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(getFileName());

    if (!fileExists)
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("expenses");
    }

    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("expense");
    xmlFile.IntoElem();
    xmlFile.AddElem("expenseId", expense.getExpenseId());
    xmlFile.AddElem("userId", expense.getUserId());
    xmlFile.AddElem("date", expense.getDate());
    xmlFile.AddElem("item", expense.getItem());
    xmlFile.AddElem("amount", AuxiliaryMethods::convertDoubleToString(expense.getAmount()));

    xmlFile.Save(getFileName());
    lastExpenseId++;
    return true;
}

int FileWithExpenses::getLastExpenseId() {
    return lastExpenseId;
}

int FileWithExpenses::getLastExpenseIdFromFile() {
    CMarkup xmlFile;
    xmlFile.Load(getFileName());
    xmlFile.FindElem();
    while (xmlFile.FindChildElem("expense")) {
        xmlFile.IntoElem();
        xmlFile.FindChildElem( "expenseId" );
        lastExpenseId = AuxiliaryMethods::convertStringToInt(xmlFile.GetChildData());
    }
    return lastExpenseId;
}

vector <Expense> FileWithExpenses::loadExpensesOfLoggedUserFromFile(int loggedUserId) {
    vector <Expense> expenses;
    Expense expense;
    CMarkup xmlFile;
    xmlFile.Load(getFileName());
    while (xmlFile.FindChildElem("expense")) {
        xmlFile.IntoElem();
        xmlFile.FindChildElem( "expenseId" );
        expense.setExpenseId(AuxiliaryMethods::convertStringToInt(xmlFile.GetChildData()));
        lastExpenseId = expense.getExpenseId();
        xmlFile.FindChildElem( "userId" );
        if (loggedUserId == AuxiliaryMethods::convertStringToInt(xmlFile.GetChildData())) {
            expense.setUserId(loggedUserId);
            xmlFile.FindChildElem( "date" );
            expense.setDate(xmlFile.GetChildData());
            xmlFile.FindChildElem( "item" );
            expense.setItem(xmlFile.GetChildData());
            xmlFile.FindChildElem( "amount" );
            expense.setAmount(AuxiliaryMethods::convertStringToDouble(xmlFile.GetChildData()));
            expenses.push_back(expense);
        }
        xmlFile.OutOfElem();
    }
    return expenses;
}
