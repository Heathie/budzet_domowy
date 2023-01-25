#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <cstring>

#include "Expenses.h"
#include "FileWithExpenses.h"
#include "Helpers.h"

using namespace std;

class ExpensesManager
{
    const int LOGGED_USER_ID; // gdzie to przeniesc?
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
    void printOutAllExpenses();
};

#endif
