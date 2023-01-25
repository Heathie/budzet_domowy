#include "UserManager.h"

void UserManager::registerUser() {
    User user = tapNewUserDataIn();

    users.push_back(user);
    fileWithUsers.writeUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::tapNewUserDataIn() {
    User user;

    user.setUserId(findNewUserId());

    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
        cin.ignore();
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    cin.ignore();
    user.setPassword(password);

    string name;
    cout << "Podaj imie: ";
    cin >> name;
    cin.ignore();
    user.setName(name);

    string surname;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    cin.ignore();
    user.setSurname(surname);

    return user;
}

int UserManager::findNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::doesLoginExist(string login) {
    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::logInUser() {
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = Helpers::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = Helpers::getLine();

                if (itr -> getPassword() == password) {
                    loggedinUserId = itr ->getUserId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::changePasswordOfLoggedInUser() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = Helpers::getLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserId() == loggedinUserId) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.writeAllUsersIntoFile(users);
}

void UserManager::logOutUser() {
    loggedinUserId = 0;
}

int UserManager::findLoggedinUserId() {
    return loggedinUserId;
}

bool UserManager::isUserLoggedIn() {
    if (loggedinUserId > 0)
        return true;
    else
        return false;
}
