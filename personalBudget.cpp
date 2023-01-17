#include "PersonalBudget.h"

void PersonalBudget::registerUser(){
    userManager.registerUser();
}

void PersonalBudget::printOutAllUsers(){
    userManager.printOutAllUsers();
}

void PersonalBudget::logInUser(){
    userManager.logInUser();
    if (userManager.isUserLoggedIn()){
        //adresatMenadzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, userManager.fingLoggedinUserId());
        userManager.findLoggedinUserId();
    }
}

void PersonalBudget::changePasswordOfLoggedInUser(){
    userManager.changePasswordOfLoggedInUser();
}

void PersonalBudget::logOutUser(){
    userManager.logOutUser();
    //delete adresatMenadzer;
    //adresatMenadzer = NULL;
}
/*
void PersonalBudget::dodajAdresata(){
    if (userManager.isUserLoggedIn()){
        adresatMenadzer->dodajAdresata();
    }
    else{
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::wyswietlWszystkichAdresatow(){
    if (userManager.isUserLoggedIn()){
        adresatMenadzer->wyswietlWszystkichAdresatow();
    }
}
*/
bool PersonalBudget::isUserLoggedIn(){
    if(userManager.isUserLoggedIn()){
        return true;
    }
    else{
        return false;
    }
}
