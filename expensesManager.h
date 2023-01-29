#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>

#include "Expenses.h"
#include "FileWithExpenses.h"
#include "Helpers.h"
#include "Dates.h"

using namespace std;

class ExpensesManager
{
    const int LOGGED_USER_ID;
    vector <Expenses> expenses;
    FileWithExpenses fileWithExpenses;

    Expenses tapNewExpenseDataIn();
    void printOutExpenseData();


public:
    ExpensesManager(int loggedUserId) : LOGGED_USER_ID(loggedUserId){
    expenses = fileWithExpenses.getExpensesOfLoggedUserFromFile(LOGGED_USER_ID);
    };
    void addExpense();
    Expenses getNewExpenseData();
    double printOutExpenses(int startDate, int endDate, double amountOfExpenses);
    void printOutExpense(Expenses expense);
    void printOutAmountOfExpensesOfPeriod(double amountOfExpenses);
};

#endif
