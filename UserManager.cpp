#include "UserManager.h"

void UserManager::userRegistration() {
    system("cls");
    User user = giveNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Account created successfully" << endl << endl;
    system("pause");
}

User UserManager::giveNewUserData() {
    User user;

    user.setUserId(getNewUserId());
    string login;

    cout << "Creating a new account" << endl;
    cout << "----------------------" << endl;

    do {
        cout << "Type in a login: ";
        cin >> login;
        user.setLogin(login);
    } while (checkIfLoginExists(user.getLogin()) == true);

    string password;
    cout << "Type in a password: ";
    cin >> password;
    user.setPassword(password);

    string name, surname;
    cout << "Type in a name: ";
    cin >> name;
    user.setName(AuxiliaryMethods::replaceFirstLetterToCapitalRestToLower(name));
    cout << "Type in a surname: ";
    cin >> surname;
    user.setSurname(AuxiliaryMethods::replaceFirstLetterToCapitalRestToLower(surname));

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::checkIfLoginExists(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Such login is exists. Please try to type in another login." << endl << endl;
            return true;
        }
    }
    return false;
}

void UserManager::userLogging() {
    system("cls");
    User user;
    string login = "", password = "";
    cout << "Log in" << endl;
    cout << "---------------------" << endl;
    cout << "Type in a login: ";
    login = AuxiliaryMethods::loadLine();

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Type in a password. Remained attempts: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (users[i].getPassword() == password) {
                    cout << endl << "Logged in." << endl << endl;
                    //system("pause");
                    loggedUserId = users[i].getUserId();
                    Sleep(1500);
                    return;
                } else if (users[i].getPassword() != password && numberOfAttempts > 1) {
                    cout << "Incorrect password. ";
                }
            }
            cout << "The password has been entered three times incorrectly." << endl;
            system("pause");
            return;
        }
    }
    cout << "Entered login doesn't exist. Please try again." << endl << endl;
    Sleep(1500);
    system("cls");
    userLogging();
}

void UserManager::loadUsersFromFile() {
    users = fileWithUsers.loadUsersFromFile();
}

void UserManager::setLoggedUserId(int newUserId) {
    loggedUserId = newUserId;
}

int UserManager::getLoggedUserId() {
    return loggedUserId;
}

bool UserManager::checkIfUserIsLogged() {
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

void UserManager::changePasswordLoggedUser() {
    string newPassword = "";
    cout << "Type in a new password: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUserId() == loggedUserId) {
            users[i].setPassword(newPassword);
            cout << "The password has been changed." << endl << endl;
            system("pause");
        }
    }
    //plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    fileWithUsers.saveAllUsersToFile(users);
}
