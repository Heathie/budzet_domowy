#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"


using namespace std;

class PersonalBudget{

    UserManager userManager;

public:
    PersonalBudget(string nameOfFileWithUsers)
        : userManager(nameOfFileWithUsers){};

    void registerUser();
    void printOutAllUsers();
    void logInUser();
    void changePasswordOfLoggedInUser();
    void logOutUser();
    bool isUserLoggedIn();

};
#endif
