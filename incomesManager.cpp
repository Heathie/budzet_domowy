#include "IncomesManager.h"

void IncomesManager::addIncome() {

    Incomes income;

    system("cls");
    cout << " >>> PODAJ DANE DOTYCZACE PRZYCHODU <<<" << endl << endl;
    income = getNewIncomeData();
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);
    cout << "Nowy przychod zostal dodany" << endl;

    system("pause");
}

Incomes IncomesManager::getNewIncomeData() {

    string incomeString;
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

void IncomesManager::printOutIncomes(int startDate, int endDate) {
    system("cls");
    bool noIncomes = true;
        cout << "                  >>> PRZYCHODY <<<" << endl;
        cout << "-------------------------------------------------------" << endl;

        sort(incomes.begin(), incomes.end(), Incomes::sortDatesOfIncomes);

        for (vector <Incomes> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (itr->getDateOfIncome() > startDate && itr->getDateOfIncome() < endDate) {
                printOutIncome(*itr);
                noIncomes = false;
            }
        }
        if(noIncomes){
            cout << "Brak przychodow w pliku" << endl;
        }
        cout << endl;

}

void IncomesManager::printOutIncome(Incomes income) {
    cout << endl << "Data przychodu:                        " << Helpers::dateToString(income.getDateOfIncome()) << endl;
    cout << "Nazwa przychodu:                        " << income.getNameOfIncome() << endl;
    cout << "Wartosc przychodu w zlotowkach:               " << income.getAmountOfIncome() << endl;
}
