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
            (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) &&
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
    do {
        cout << "Wprowadz date (YYYY-MM-DD): ";
        getline(cin, rawInput);
        date = stringToDate(rawInput);
    } while(!Helpers::isValidDate(date));

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

int Helpers::getFirstDayOfThisMonth(int startDate) {
    int date = getCurrentDate();
    string stringDate = dateToString(date);
    string stringMonth = stringDate.substr(5, 2);
    string stringYear = stringDate.substr(0, 4);
    stringDate = stringYear + "-" + stringMonth + "-01";
    return startDate = stringToDate(stringDate);
}
int Helpers::getLastDayOfThisMonth(int endDate) {
    int date = getCurrentDate();
    string stringDate = dateToString(date);
    string stringMonth = stringDate.substr(5, 2);
    string stringYear = stringDate.substr(0, 4);
    int month = convertStringToInt(stringMonth);
    int year = convertStringToInt(stringYear);

    switch(month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        stringDate = stringYear + "-" + stringMonth + "-31";
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        stringDate = stringYear + "-" + stringMonth + "-30";
        break;

    case 2: {
        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
            stringDate = stringYear + "-" + stringMonth + "-29";
        else stringDate = stringYear + "-" + stringMonth + "-28";
    }
    }
    return endDate = stringToDate(stringDate);
}

int Helpers::getFirstDayOfPreviousMonth(int startDate){
    int month = 0;
    int date = getCurrentDate();
    string stringDate = dateToString(date);
    string stringMonth = stringDate.substr(5, 2);
    string stringYear = stringDate.substr(0, 4);
    if (stringMonth[0] == '0' && stringMonth[1] != '1'){
        stringMonth = stringMonth.erase(0, 1);
        month = convertStringToInt(stringMonth);
        month = month - 1;
        stringMonth = month < 10 ? "0" + convertIntToString(month) : convertIntToString(month);
    } else if(stringMonth[0] == '0' && stringMonth[1] == '1'){
        month = 12;
        stringMonth = month < 10 ? "0" + convertIntToString(month) : convertIntToString(month);
    } else{
        month = convertStringToInt(stringMonth);
        month = month - 1;
        stringMonth = convertIntToString(month);
    }
    stringDate = stringYear + "-" + stringMonth + "-01";
    return startDate = stringToDate(stringDate);
}

int Helpers::getLastDayOfPreviousMonth(int endDate){
    int month = 0;
    int date = getCurrentDate();
    string stringDate = dateToString(date);
    string stringMonth = stringDate.substr(5, 2);
    string stringYear = stringDate.substr(0, 4);
    int year = convertStringToInt(stringYear);
    if (stringMonth[0] == '0' && stringMonth[1] != '1'){
        stringMonth = stringMonth.erase(0, 1);
        month = convertStringToInt(stringMonth);
        month = month - 1;
        stringMonth = month < 10 ? "0" + convertIntToString(month) : convertIntToString(month);
    } else if(stringMonth[0] == '0' && stringMonth[1] == '1'){
        month = 12;
        stringMonth = convertIntToString(month);
    } else{
        month = convertStringToInt(stringMonth);
        month = month - 1;
        stringMonth = convertIntToString(month);
    }

    switch(month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        stringDate = stringYear + "-" + stringMonth + "-31";
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        stringDate = stringYear + "-" + stringMonth + "-30";
        break;

    case 2: {
        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
            stringDate = stringYear + "-" + stringMonth + "-29";
        else stringDate = stringYear + "-" + stringMonth + "-28";
    }
    }
    return endDate = stringToDate(stringDate);
}

int Helpers::getStartDate(int startDate) {
    cout << "Data poczatkowa." << " ";
    startDate = Helpers::getDate();
    return startDate;
}

int Helpers::getEndDate(int endDate) {
    cout << "Data koncowa." << " ";
    endDate = Helpers::getDate();
    return endDate;
}
