#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <windows.h>


using namespace std;

class Helpers
{
public:
    static string convertIntToString(int number);
    static string getLine();
    static string changeFirstLetterToUpperAndRestToLower(string text);
    static int convertStringToInt(string number);
    static string getDigit(string text, int signPosition);
    static char chooseOptionFromMainMenu();
    static char chooseOptionFromUserMenu();
    static char getChar();
    static int getInteger();
    static char chooseOptionFromDateMenu();
    static int getDate();
    static string dateToString(int date);
    static int stringToDate(string sDate);
    static int getCurrentDate();
    static bool isLeapYear(int year);
    static bool isValidDate(int date);
    static int getStartDate(int startDate);
    static int getEndDate(int endDate);
    static int getFirstDayOfThisMonth(int startDate);
    static int getLastDayOfThisMonth(int endDate);
    static int getFirstDayOfPreviousMonth(int startDate);
    static int getLastDayOfPreviousMonth(int endDate);
};

#endif
