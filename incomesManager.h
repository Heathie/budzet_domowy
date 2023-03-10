#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>

#include "Incomes.h"
#include "FileWithIncomes.h"
#include "Helpers.h"
#include "Dates.h"

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
    double printOutIncomes(int startDate, int endDate, double amountOfIncomes);
    void printOutIncome(Incomes income);
    void printOutAmountOfIncomesOfPeriod(double amountOfIncomes);
};

#endif
