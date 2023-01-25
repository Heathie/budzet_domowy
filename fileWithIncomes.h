#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Incomes.h"
#include "Helpers.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes
{
    string nameOfFileWithIncomes;
    int idOfLastIncome;
    Incomes getIncomeData();

public:
    FileWithIncomes(){
        idOfLastIncome = 0;
    };
    void addIncomeToFile(Incomes incomes);
    vector <Incomes> getIncomesOfLoggedUserFromFile(int loggedUserId);
    int getIdOfLastIncome();
};
#endif
