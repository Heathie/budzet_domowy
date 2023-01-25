#include "FileWithExpenses.h"

int FileWithExpenses::getIdOfLastExpense() {
    return idOfLastExpense;
}

void FileWithExpenses::addExpenseToFile(Expenses expense) {
    idOfLastExpense = expense.getIdOfExpense();
    CMarkup xml;
    bool fileExists = xml.Load("Expenses.xml");
    if(!fileExists) {
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("idOfExpense", expense.getIdOfExpense());
    xml.AddElem("idOfUserWhichExpensesBelongsTo", expense.getIdOfUserWhichExpensesBelongsTo());
    xml.AddElem("dateOfExpense", Helpers::dateToString(expense.getDateOfExpense()));
    xml.AddElem("nameOfExpense", expense.getNameOfExpense());
    xml.AddElem("amountOfExpense", expense.getAmountOfExpense());

    xml.Save("Expenses.xml");
}

vector <Expenses> FileWithExpenses::getExpensesOfLoggedUserFromFile(int loggedUserId) {

    vector <Expenses> expenses;
    int lastExpenseId = 0;
    CMarkup xml;
    xml.Load("Expenses.xml");
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Expense")) {
        Expenses tempExpenses;

        xml.IntoElem();

        xml.FindElem();
        lastExpenseId = stoi(xml.GetData());
        tempExpenses.setIdOfExpense(lastExpenseId);

        xml.FindElem();
        tempExpenses.setIdOfUserWhichExpensesBelongsTo(stoi(xml.GetData()));

        xml.FindElem();
        tempExpenses.setDateOfExpense(Helpers::stringToDate(xml.GetData()));

        xml.FindElem();
        tempExpenses.setNameOfExpense(xml.GetData());

        xml.FindElem();
        tempExpenses.setAmountOfExpense(xml.GetData());

        xml.OutOfElem();

        expenses.push_back(tempExpenses);
    }

    idOfLastExpense = lastExpenseId;

    return expenses;
}
