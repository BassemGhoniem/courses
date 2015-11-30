/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the numeric-conversion problem
 * in which you implement the functions intToString and stringToInt.
 * [TODO: rewrite the documentation]
 */
#include <sstream>
#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
using namespace std;


string intToString(int n);
int stringToInt(string str);
int unsignedIntfromStr(string str);


int main() {
   int x = getInteger("Please give me an Integer: ");
   cout << stringToInt(intToString(x)) << endl;
   return 0;
}


string intToString(int n) {
    if (!(n / 10))
        return string("") + char ('0' + n % 10);
    else
        return intToString(n / 10) +intToString( n % 10);
}


int stringToInt(string str) {
    if (str[0] == '-')
        return - unsignedIntfromStr(str.substr(1));
    else
        return unsignedIntfromStr(str);
}


int unsignedIntfromStr(string str) {
    if (str.length() == 1)
        return str[0] - '0';
    else
        return stringToInt(str.substr(0, str.length() - 1)) * 10 + (str[str.length() - 1] - '0');
}
