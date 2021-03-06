#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager {
    int loggedUserId;
    vector <User> users;

    User giveNewUserData();
    int getNewUserId();
    bool checkIfLoginExists(string login);
    FileWithUsers fileWithUsers;
public:
    UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
        loggedUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void userRegistration();
    void userLogging();
    void loadUsersFromFile();
    void setLoggedUserId(int newUserId);
    int getLoggedUserId();
    void changePasswordLoggedUser();
    bool checkIfUserIsLogged();
    void userLogOut();
};

#endif
