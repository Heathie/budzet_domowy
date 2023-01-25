#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"


using namespace std;

class PersonalBudget {

    UserManager userManager;
    IncomesManager *incomesManager;
    ExpensesManager *expensesManager;

public:
    PersonalBudget(string nameOfFileWithUsers) : userManager(nameOfFileWithUsers) {
        incomesManager = NULL;
        expensesManager = NULL;
    };
    ~PersonalBudget() {
        delete incomesManager;
        incomesManager = NULL;
        delete expensesManager;
        expensesManager = NULL;
    };
    void registerUser();
    void logInUser();
    void changePasswordOfLoggedInUser();
    void logOutUser();
    bool isUserLoggedIn();
    void addIncome();
    void printOutAllIncomes();
    void addExpense();

};
#endif
