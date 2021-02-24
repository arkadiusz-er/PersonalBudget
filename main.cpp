#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml");
    //personalBudget.userRegistration();
    personalBudget.userLogging();
    //personalBudget.displayIncomes();
    personalBudget.addIncome();
    personalBudget.displayIncomes();
}
