#include "ExpensesManager.h"

void ExpensesManager::addExpense() {

    Expenses expense;

    system("cls");
    cout << " >>> PODAJ DANE DOTYCZACE WYDATKU <<<" << endl << endl;
    expense = getNewExpenseData();
    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);
    cout << "Nowy wydatek zostal dodany" << endl;

    system("pause");
}

Expenses ExpensesManager::getNewExpenseData() {

    string expenseString;
    int date;
    char option;

    do {
        option = Helpers::chooseOptionFromDateMenu();
    } while(option != '1' && option != '2');

    switch (option) {
    case '1':
        date = Helpers::getCurrentDate();
        break;
    case '2':
        date = Helpers::getDate();
        break;
    }

    Expenses expense;

    expense.setIdOfExpense((fileWithExpenses.getIdOfLastExpense() + 1));
    expense.setIdOfUserWhichExpensesBelongsTo(LOGGED_USER_ID);

    expense.setDateOfExpense(date);

    cout << "Podaj czego dotyczy wydatek: ";
    expense.setNameOfExpense(Helpers::getLine());

    cout << "Podaj kwote wydatku: ";
    expenseString = Helpers::getLine();
    replace(expenseString.begin(), expenseString.end(), ',', '.');
    expense.setAmountOfExpense(expenseString);

    return expense;
}

void ExpensesManager::printOutAllExpenses() {

}
