/*
 * File: Obenglobish.java
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Obenglobish problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Main program */

string obenglish(string word);
int vowelIndex(string word);
bool isVowel(char ch);

int main() {
   while (true) {
       string word = getLine("Enter a word: ");
       if (word == "") break;
       string trans = obenglish(word);
       cout << word << " -> " << trans << endl;
   }
   return 0;
}

string obenglish(string word) {
    string result = "";
    bool thereVowel = false;
    for (int i = 0, n = word.length(); i < n; i++)
        if (isVowel(word[i]) && !thereVowel) {
            if (word[i]== 'e' && i == n - 1)
                result += word[i];
            else
                result += string ("ob") + word[i];
            thereVowel = true;
        } else {
            if (!isVowel(word[i]))
                thereVowel = false;
            result += word[i];
        }
    return result;
}

bool isVowel(char ch) {
    switch (ch) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
        return true;
    default :
        return false;
    }
}
