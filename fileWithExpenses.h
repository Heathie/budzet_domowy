#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Expenses.h"
#include "Helpers.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses
{
    string nameOfFileWithExpenses;
    int idOfLastExpense;
    Expenses getExpenseData();

public:
    FileWithExpenses(){
        idOfLastExpense = 0;
    };
    void addExpenseToFile(Expenses expenses);
    vector <Expenses> getExpensesOfLoggedUserFromFile(int loggedUserId);
    int getIdOfLastExpense();
};
#endif
