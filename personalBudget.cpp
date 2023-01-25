#include "PersonalBudget.h"

void PersonalBudget::registerUser(){
    userManager.registerUser();
}

void PersonalBudget::logInUser(){
    userManager.logInUser();
    if (userManager.isUserLoggedIn()){
        incomesManager = new IncomesManager(userManager.findLoggedinUserId());
        expensesManager = new ExpensesManager(userManager.findLoggedinUserId());
    }
}

void PersonalBudget::changePasswordOfLoggedInUser(){
    userManager.changePasswordOfLoggedInUser();
}

void PersonalBudget::logOutUser(){
    userManager.logOutUser();
    delete incomesManager;
    delete expensesManager;
    incomesManager = NULL;
    expensesManager = NULL;
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

void PersonalBudget::addExpense(){
    if (userManager.isUserLoggedIn()){
        expensesManager->addExpense();
    }
    else{
        cout << "Aby dodac wydatek, nalezy najpierw sie zalogowac" << endl;
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
