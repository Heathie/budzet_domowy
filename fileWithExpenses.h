#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expenses.h"
#include "Helpers.h"
#include "Markup.h"
#include "Dates.h"

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
