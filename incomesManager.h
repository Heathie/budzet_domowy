#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <cstring>

#include "Incomes.h"
#include "FileWithIncomes.h"
#include "Helpers.h"

using namespace std;

class IncomesManager
{
    const int LOGGED_USER_ID;
    vector <Incomes> incomes;
    FileWithIncomes fileWithIncomes;

    Incomes tapNewIncomeDataIn();
    void printOutIncomeData();


public:
    IncomesManager(int loggedUserId) : LOGGED_USER_ID(loggedUserId){
    incomes = fileWithIncomes.getIncomesOfLoggedUserFromFile(LOGGED_USER_ID);
    };
    void addIncome();
    Incomes getNewIncomeData();
    void printOutAllIncomes();
};

#endif
