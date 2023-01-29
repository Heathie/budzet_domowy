#include "Helpers.h"

string Helpers::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string Helpers::getLine() {
    string input = "";
    getline(cin, input);
    return input;
}

string Helpers::changeFirstLetterToUpperAndRestToLower(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int Helpers::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

double Helpers::convertStringToDouble(string number){
    double numberDouble = stod(number);
    return numberDouble;
}

string Helpers::getDigit(string text, int markerPosition) {
    string number = "";
    while(isdigit(text[markerPosition]) == true) {
        number += text[markerPosition];
        markerPosition ++;
    }
    return number;
}

char Helpers::chooseOptionFromMainMenu() {
    char option;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    option = getChar();

    return option;
}

char Helpers::chooseOptionFromUserMenu() {
    char option;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    option = getChar();

    return option;
}

char Helpers::getChar() {
    string input = "";
    char marker  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            marker = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return marker;
}

int Helpers::getInteger() {
    string input = "";
    int number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}
