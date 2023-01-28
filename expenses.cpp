#include "Expenses.h"

void Expenses::setIdOfExpense(int newIdOfExpense){
    if (newIdOfExpense >= 0)
        idOfExpense = newIdOfExpense;
}
void Expenses::setIdOfUserWhichExpensesBelongsTo(int newIdOfUserWhichExpensesBelongsTo){
    idOfUserWhichExpensesBelongsTo = newIdOfUserWhichExpensesBelongsTo;
}
void Expenses::setDateOfExpense(int newDateOfExpense){
    dateOfExpense = newDateOfExpense;
}
void Expenses::setNameOfExpense(string newNameOfExpense){
    nameOfExpense = newNameOfExpense;
}
void Expenses::setAmountOfExpense(string newAmountOfExpense){
    amountOfExpense = newAmountOfExpense;
}

int Expenses::getIdOfExpense(){
    return idOfExpense;
}
int Expenses::getIdOfUserWhichExpensesBelongsTo(){
    return idOfUserWhichExpensesBelongsTo;
}
int Expenses::getDateOfExpense(){
    return dateOfExpense;
}
string Expenses::getNameOfExpense(){
    return nameOfExpense;
}
string Expenses::getAmountOfExpense(){
    return amountOfExpense;
}

bool Expenses::sortDatesOfExpenses(Expenses one, Expenses two){
    return one.getDateOfExpense() < two.getDateOfExpense();
}
