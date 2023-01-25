#include "IncomesManager.h"

void IncomesManager::addIncome(){

    Incomes income;

    system("cls");
    cout << " >>> PODAJ DANE DOTYCZACE PRZYCHODU <<<" << endl << endl;
    income = getNewIncomeData();
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);
    cout << "Nowy przychod zostal dodany" << endl;

    system("pause");
}

Incomes IncomesManager::getNewIncomeData(){
    char option = Helpers::chooseOptionFromDateMenu();
    string incomeString;
    int date;

    if (option == '1') {
        date = Helpers::getCurrentDate();
    } else if (option == '2') {
        date = Helpers::getDate();
    }

    Incomes income;

    income.setIdOfIncome((fileWithIncomes.getIdOfLastIncome() + 1));
    income.setIdOfUserWhichIncomesBelongsTo(LOGGED_USER_ID);

    income.setDateOfIncome(date);

    cout << "Podaj czego dotyczy przychod: ";
    income.setNameOfIncome(Helpers::getLine());

    cout << "Podaj kwote przychodu: ";
    incomeString = Helpers::getLine();
    replace(incomeString.begin(), incomeString.end(), ',', '.');
    income.setAmountOfIncome(incomeString);

    return income;
}

void IncomesManager::printOutAllIncomes(){

}
