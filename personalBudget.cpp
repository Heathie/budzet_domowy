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

bool PersonalBudget::isUserLoggedIn(){
    if(userManager.isUserLoggedIn()){
        return true;
    }
    else{
        return false;
    }
}

void PersonalBudget::printOutBalanceSheet(string timePeriod){
    int startDate = 0, endDate = 0;
    double amountOfExpenses = 0, amountOfIncomes = 0, balanceSheet = 0;
    system("cls");
    if (userManager.isUserLoggedIn()){
        if(timePeriod == "currentMonth"){
            startDate = Dates::getFirstDayOfThisMonth(startDate);
            endDate = Dates::getLastDayOfThisMonth(endDate);
        }
        else if(timePeriod == "previousMonth"){
            startDate = Dates::getFirstDayOfPreviousMonth(startDate);
            endDate = Dates::getLastDayOfPreviousMonth(endDate);
        }
        else{
            startDate = Dates::getStartDate(startDate);
            endDate = Dates::getEndDate(endDate);
        }
        system("cls");
        cout << "Od " << Dates::dateToString(startDate) << " do " << Dates::dateToString(endDate) << endl;
        amountOfIncomes = incomesManager->printOutIncomes(startDate, endDate, amountOfIncomes);
        amountOfExpenses = expensesManager->printOutExpenses(startDate, endDate, amountOfExpenses);
        incomesManager->printOutAmountOfIncomesOfPeriod(amountOfIncomes);
        expensesManager->printOutAmountOfExpensesOfPeriod(amountOfExpenses);
        balanceSheet = amountOfIncomes - amountOfExpenses;
        cout << "Roznica miedzy przychodami, a wydatkami:        " << balanceSheet << "zl" << endl;
        system("pause");
    }
    else{
        cout << "Aby wyswietlic bilans, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}
