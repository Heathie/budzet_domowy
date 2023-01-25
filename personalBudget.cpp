#include "PersonalBudget.h"

void PersonalBudget::registerUser(){
    userManager.registerUser();
}

void PersonalBudget::logInUser(){
    userManager.logInUser();
    if (userManager.isUserLoggedIn()){
        incomesManager = new IncomesManager(userManager.findLoggedinUserId());
    }
}

void PersonalBudget::changePasswordOfLoggedInUser(){
    userManager.changePasswordOfLoggedInUser();
}

void PersonalBudget::logOutUser(){
    userManager.logOutUser();
    delete incomesManager;
    incomesManager = NULL;
}

void PersonalBudget::addIncome(){
    if (userManager.isUserLoggedIn()){
        incomesManager->addIncome();
    }
    else{
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::printOutAllIncomes(){
    if (userManager.isUserLoggedIn()){
        incomesManager->printOutAllIncomes();
    }
}

bool PersonalBudget::isUserLoggedIn(){
    if(userManager.isUserLoggedIn()){
        return true;
    }
    else{
        return false;
    }
}
