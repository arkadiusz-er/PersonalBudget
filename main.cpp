#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");
    //personalBudget.userRegistration();
    personalBudget.userLogging();
}
