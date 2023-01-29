#include "FileWithIncomes.h"

int FileWithIncomes::getIdOfLastIncome() {
    return idOfLastIncome;
}

void FileWithIncomes::addIncomeToFile(Incomes income) {
    idOfLastIncome = income.getIdOfIncome();
    CMarkup xml;
    bool fileExists = xml.Load("Incomes.xml");
    if(!fileExists) {
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("idOfIncome", income.getIdOfIncome());
    xml.AddElem("idOfUserWhichIncomesBelongsTo", income.getIdOfUserWhichIncomesBelongsTo());
    xml.AddElem("dateOfIncome", Dates::dateToString(income.getDateOfIncome()));
    xml.AddElem("nameOfIncome", income.getNameOfIncome());
    xml.AddElem("amountOfIncome", income.getAmountOfIncome());

    xml.Save("Incomes.xml");
}

vector <Incomes> FileWithIncomes::getIncomesOfLoggedUserFromFile(int loggedUserId) {

    vector <Incomes> incomes;
    int lastIncomeId = 0;
    CMarkup xml;
    xml.Load("Incomes.xml");
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Income")) {
        Incomes tempIncomes;

        xml.IntoElem();

        xml.FindElem();
        lastIncomeId = stoi(xml.GetData());
        tempIncomes.setIdOfIncome(lastIncomeId);

        xml.FindElem();
        tempIncomes.setIdOfUserWhichIncomesBelongsTo(stoi(xml.GetData()));

        xml.FindElem();
        tempIncomes.setDateOfIncome(Dates::stringToDate(xml.GetData()));

        xml.FindElem();
        tempIncomes.setNameOfIncome(xml.GetData());

        xml.FindElem();
        tempIncomes.setAmountOfIncome(xml.GetData());

        xml.OutOfElem();

        if(tempIncomes.getIdOfUserWhichIncomesBelongsTo() == loggedUserId){
        incomes.push_back(tempIncomes);
        }
    }

    idOfLastIncome = lastIncomeId;

    return incomes;
}
