#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>

using namespace std;

class Expenses{
    int idOfExpense;
    int idOfUserWhichExpensesBelongsTo;
    int dateOfExpense;
    string nameOfExpense;
    string amountOfExpense;
public:
    void setIdOfExpense(int newIdOfExpense);
    void setIdOfUserWhichExpensesBelongsTo(int newIdOfUserWhichExpensesBelongsTo);
    void setDateOfExpense(int newDateOfExpense);
    void setNameOfExpense(string newNameOfExpense);
    void setAmountOfExpense(string newAmountOfExpense);

    int getIdOfExpense();
    int getIdOfUserWhichExpensesBelongsTo();
    int getDateOfExpense();
    string getNameOfExpense();
    string getAmountOfExpense();
    static bool sortDatesOfExpenses(Expenses one, Expenses two);

};

#endif
