#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    char choice;
    while (true) {
        if (!personalBudget.checkIfUserIsLogged()) {
            choice = personalBudget.chooseOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Indicated option doesn't exist." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = personalBudget.chooseOptionFromUserMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayBalanceFromCurrentMonth();
                break;
            case '4':
                personalBudget.displayBalanceFromPreviousMonth();
                break;
            case '5':
                personalBudget.displayBalanceFromChosenPeriod();
                break;
            case '6':
                personalBudget.changePasswordLoggedUser();
                break;
            case '7':
                //personalBudget.zmianaHaslaZalogowanegoUzytkownika();
                break;
            }
        }
    }

    return 0;
}
