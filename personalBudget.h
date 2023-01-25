#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "incomesManager.h"


using namespace std;

class PersonalBudget {

    UserManager userManager;
    IncomesManager *incomesManager;

public:
    PersonalBudget(string nameOfFileWithUsers) : userManager(nameOfFileWithUsers) {
        incomesManager = NULL;
    };
    ~PersonalBudget() {
        delete incomesManager;
        incomesManager = NULL;
    };
    void registerUser();
    void logInUser();
    void changePasswordOfLoggedInUser();
    void logOutUser();
    bool isUserLoggedIn();
    void addIncome();
    void printOutAllIncomes();

};
#endif
