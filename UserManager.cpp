#include "UserManager.h"

void UserManager::userRegistration() {
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
    user.setName(name);
    cout << "Type in a surname: ";
    cin >> surname;
    user.setSurname(surname);

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
            cout << endl << "Such login is exists. Please try type in another login." << endl;
            return true;
        }
    }
    return false;
}
