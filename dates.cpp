#include "Dates.h"

bool Dates::isLeapYear(int year) {
    return year % 4 == 0 && (
               year % 100 != 0 ||
               year % 400 == 0
           );
}

int Dates::getCurrentDate() {
    string currentDate;
    int date = 0;
    time_t t = time(0);;
    tm* now = localtime(&t);
    int month = now->tm_mon + 1;
    int day = now->tm_mday;
    currentDate =
        Helpers::convertIntToString(now->tm_year + 1900) +
        (month < 10 ? "0" + Helpers::convertIntToString(month) : Helpers::convertIntToString(month)) +
        (day < 10 ? "0" + Helpers::convertIntToString(day) : Helpers::convertIntToString(day));

    date = stoi(currentDate);

    return date;
}

bool Dates::isValidDate(int date) {
    int day = date % 100;
    int month = (date / 100) % 100;
    int year = date / 10000;

    int currentDate = getCurrentDate();
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
                (isLeapYear(year) && day > 29) ||
                (!isLeapYear(year) && day > 28)
            )
        ) ||
        (
            (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) &&
            day > 31
        ) || (
            (month == 4 || month == 6 || month == 9 || month == 11) && day > 30
        )
    ) {
        cout << "Nieprawidlowy format daty" << endl;
        Sleep(1000);
        return false;
    }

    return true;
}

int Dates::stringToDate(string s) {
    string year = s.substr(0, 4);
    string month = s.substr(5, 2);
    string day = s.substr(8,2);

    return stoi(year + month + day);
}

int Dates::getDate() {
    string rawInput;
    int date = 0;
    do {
        cout << "Wprowadz date (YYYY-MM-DD): ";
        getline(cin, rawInput);
        date = stringToDate(rawInput);
    } while(!isValidDate(date));

    return date;
}

char Dates::chooseOptionFromDateMenu() {
    char marker;

    cout << endl << "   >>> WYBIERZ DZIEN, KTOREGO DOTYCZY TRANSAKCJA <<<" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "1. Dzis" << endl;
    cout << "2. Inny dzien" << endl;
    cout << endl << "Twoj wybor: ";
    marker = Helpers::getChar();

    return marker;
}

string Dates::dateToString(int date) {
    string year, month, day;

    day = Helpers::convertIntToString(date % 100);
    if (date % 100 < 10) {
        day = "0" + day;
    }
    date = date / 100;
    month = Helpers::convertIntToString(date % 100);
    if (date % 100 < 10) {
        month = "0" + month;
    }
    date = date / 100;

    year = Helpers::convertIntToString(date);

    return year + "-" + month + "-" + day;
}

int Dates::getFirstDayOfThisMonth(int startDate) {
    int date = getCurrentDate();
    string stringDate = dateToString(date);
    string stringMonth = stringDate.substr(5, 2);
    string stringYear = stringDate.substr(0, 4);
    stringDate = stringYear + "-" + stringMonth + "-01";
    return startDate = stringToDate(stringDate);
}
int Dates::getLastDayOfThisMonth(int endDate) {
    int date = getCurrentDate();
    string stringDate = dateToString(date);
    string stringMonth = stringDate.substr(5, 2);
    string stringYear = stringDate.substr(0, 4);
    int month = Helpers::convertStringToInt(stringMonth);
    int year = Helpers::convertStringToInt(stringYear);

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

int Dates::getFirstDayOfPreviousMonth(int startDate){
    int month = 0;
    int date = getCurrentDate();
    string stringDate = dateToString(date);
    string stringMonth = stringDate.substr(5, 2);
    string stringYear = stringDate.substr(0, 4);
    if (stringMonth[0] == '0' && stringMonth[1] != '1'){
        stringMonth = stringMonth.erase(0, 1);
        month = Helpers::convertStringToInt(stringMonth);
        month = month - 1;
        stringMonth = month < 10 ? "0" + Helpers::convertIntToString(month) : Helpers::convertIntToString(month);
    } else if(stringMonth[0] == '0' && stringMonth[1] == '1'){
        month = 12;
        stringMonth = month < 10 ? "0" + Helpers::convertIntToString(month) : Helpers::convertIntToString(month);
    } else{
        month = Helpers::convertStringToInt(stringMonth);
        month = month - 1;
        stringMonth = Helpers::convertIntToString(month);
    }
    stringDate = stringYear + "-" + stringMonth + "-01";
    return startDate = stringToDate(stringDate);
}

int Dates::getLastDayOfPreviousMonth(int endDate){
    int month = 0;
    int date = getCurrentDate();
    string stringDate = dateToString(date);
    string stringMonth = stringDate.substr(5, 2);
    string stringYear = stringDate.substr(0, 4);
    int year = Helpers::convertStringToInt(stringYear);
    if (stringMonth[0] == '0' && stringMonth[1] != '1'){
        stringMonth = stringMonth.erase(0, 1);
        month = Helpers::convertStringToInt(stringMonth);
        month = month - 1;
        stringMonth = month < 10 ? "0" + Helpers::convertIntToString(month) : Helpers::convertIntToString(month);
    } else if(stringMonth[0] == '0' && stringMonth[1] == '1'){
        month = 12;
        stringMonth = Helpers::convertIntToString(month);
    } else{
        month = Helpers::convertStringToInt(stringMonth);
        month = month - 1;
        stringMonth = Helpers::convertIntToString(month);
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

int Dates::getStartDate(int startDate) {
    cout << "Data poczatkowa." << " ";
    startDate = getDate();
    return startDate;
}

int Dates::getEndDate(int endDate) {
    cout << "Data koncowa." << " ";
    endDate = getDate();
    return endDate;
}
