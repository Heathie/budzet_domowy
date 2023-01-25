#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("Users.xml");

    char marker;

    while (true)
    {
        if (personalBudget.isUserLoggedIn() == false)
        {
            marker = Helpers::chooseOptionFromMainMenu();

            switch (marker)
            {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            marker = Helpers::chooseOptionFromUserMenu();

            switch (marker)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':

                break;
            case '3':

                break;
            case '4':
                //personalBudget.wyswietlWszystkichAdresatow();
                break;
            case '5':

                break;
            case '6':
                personalBudget.changePasswordOfLoggedInUser();
                break;
            case '7':
                personalBudget.logOutUser();
                break;
            }
        }
    }
    return 0;
}
