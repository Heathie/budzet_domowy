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
    option = Helpers::getChar();

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
    option = Helpers::getChar();

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

bool Helpers::isLeapYear(int year) {
    return year % 4 == 0 && (
        year % 100 != 0 ||
        year % 400 == 0
    );
}

int Helpers::getCurrentDate() {
    string currentDate;
    int date = 0;
    time_t t = time(0);;
    tm* now = localtime(&t);
    int month = now->tm_mon + 1;
    int day = now->tm_mday;
    currentDate =
        convertIntToString(now->tm_year + 1900) +
        (month < 10 ? "0" + convertIntToString(month) : convertIntToString(month)) +
        (day < 10 ? "0" + convertIntToString(day) : convertIntToString(day));

    date = stoi(currentDate);

    return date;
}

bool Helpers::isValidDate(int date) {
    int day = date % 100;
    int month = (date / 100) % 100;
    int year = date / 10000;

    int currentDate = Helpers::getCurrentDate();
    int currentMonth = (currentDate / 100) % 100;
    int currentYear = currentDate / 10000;

    if (
        year < 2000 ||
        year > currentYear ||
        month < 1 ||
        month > 12 ||
        (year == currentYear && month > currentMonth) ||
        day < 1 ||
        (
            month == 2 && (
                (Helpers::isLeapYear(year) && day > 29) ||
                day > 28
            )
        ) ||
        (
            month % 2 == 1 &&
            day > 31
        ) ||
        day > 30
    ) {
        cout << "Nieprawidlowy format daty" << endl;
        Sleep(1000);
        return false;
    }

    return true;
}

int Helpers::stringToDate(string s) {
    string year = s.substr(0, 4);
    string month = s.substr(5, 2);
    string day = s.substr(8,2);

    return stoi(year + month + day);
}

int Helpers::getDate() {
    string rawInput;
    int date = 0;
    do{
    cout << "Wprowadz date (YYYY-MM-DD): " << endl;
    getline(cin, rawInput);
    date = stringToDate(rawInput);
    }while(!Helpers::isValidDate(date));

    return date;
}

char Helpers::chooseOptionFromDateMenu() {
    char marker;

    cout << endl << "   >>> WYBIERZ DZIEN, KTOREGO DOTYCZY TRANSAKCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dzis" << endl;
    cout << "2. Inny dzien" << endl;
    cout << endl << "Twoj wybor: ";
    marker = Helpers::getChar();

    return marker;
}

string Helpers::dateToString(int date) {
    string year, month, day;

    day = convertIntToString(date % 100);
    if (date % 100 < 10) {
        day = "0" + day;
    }
    date = date / 100;
    month = convertIntToString(date % 100);
    if (date % 100 < 10) {
        month = "0" + month;
    }
    date = date / 100;

    year = convertIntToString(date);

    return year + "-" + month + "-" + day;
}
