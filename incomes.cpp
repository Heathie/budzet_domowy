#include "Incomes.h"

void Incomes::setIdOfIncome(int newIdOfIncome){
    if (newIdOfIncome >= 0)
        idOfIncome = newIdOfIncome;
}
void Incomes::setIdOfUserWhichIncomesBelongsTo(int newIdOfUserWhichIncomesBelongsTo){
    idOfUserWhichIncomesBelongsTo = newIdOfUserWhichIncomesBelongsTo;
}
void Incomes::setDateOfIncome(int newDateOfIncome){
    dateOfIncome = newDateOfIncome;
}
void Incomes::setNameOfIncome(string newNameOfIncome){
    nameOfIncome = newNameOfIncome;
}
void Incomes::setAmountOfIncome(string newAmountOfIncome){
    amountOfIncome = newAmountOfIncome;
}

int Incomes::getIdOfIncome(){
    return idOfIncome;
}
int Incomes::getIdOfUserWhichIncomesBelongsTo(){
    return idOfUserWhichIncomesBelongsTo;
}
int Incomes::getDateOfIncome(){
    return dateOfIncome;
}
string Incomes::getNameOfIncome(){
    return nameOfIncome;
}
string Incomes::getAmountOfIncome(){
    return amountOfIncome;
}

bool Incomes::sortDatesOfIncomes(Incomes one, Incomes two){
    return one.getDateOfIncome() < two.getDateOfIncome();
}
