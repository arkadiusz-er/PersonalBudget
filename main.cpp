#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    //personalBudget.userRegistration();
    personalBudget.userLogging();
    //personalBudget.displayIncomes();
    //personalBudget.addIncome();
    //personalBudget.addExpense();
    //personalBudget.addExpense();
    //personalBudget.displayIncomesFromCurrentMonth();
    //personalBudget.displayIncomesFromPreviousMonth();
    //personalBudget.displayIncomesFromChosenPeriod();
    //personalBudget.displayExpensesFromCurrentMonth();
    //personalBudget.displayExpensesFromPreviousMonth();
    //personalBudget.displayBalanceFromCurrentMonth();
    //personalBudget.displayBalanceFromPreviousMonth();
    personalBudget.displayBalanceFromChosenPeriod();
    //personalBudget.displayExpensesFromChosenPeriod();
}
