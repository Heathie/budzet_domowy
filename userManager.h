#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"
#include "Helpers.h"

using namespace std;

class UserManager
{
    int loggedinUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User tapNewUserDataIn();
    int findNewUserId();
    bool doesLoginExist(string login);

public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers) {
        loggedinUserId = 0;
        users = fileWithUsers.loadAllUsersFromFile();
    };
    void registerUser();
    void printOutAllUsers();
    void logInUser();
    void changePasswordOfLoggedInUser();
    void logOutUser();
    bool isUserLoggedIn();
    int findLoggedinUserId();
};

#endif
