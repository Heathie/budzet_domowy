#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>

using namespace std;

class Incomes {
    int idOfIncome;
    int idOfUserWhichIncomesBelongsTo;
    int dateOfIncome;
    string nameOfIncome;
    string amountOfIncome;
public:
    void setIdOfIncome(int newIdOfIncome);
    void setIdOfUserWhichIncomesBelongsTo(int newIdOfUserWhichIncomesBelongsTo);
    void setDateOfIncome(int newDateOfIncome);
    void setNameOfIncome(string newNameOfIncome);
    void setAmountOfIncome(string newAmountOfIncome);

    int getIdOfIncome();
    int getIdOfUserWhichIncomesBelongsTo();
    int getDateOfIncome();
    string getNameOfIncome();
    string getAmountOfIncome();

};

#endif
