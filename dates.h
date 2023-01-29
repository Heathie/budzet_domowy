#ifndef DATES_H
#define DATES_H

#include <ctime>
#include <windows.h>

#include "Helpers.h"


using namespace std;

class Dates
{
public:
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
