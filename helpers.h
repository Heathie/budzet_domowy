#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

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
};

#endif
