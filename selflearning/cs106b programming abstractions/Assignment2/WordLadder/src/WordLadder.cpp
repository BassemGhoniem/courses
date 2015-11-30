/*
 * File: WordLadder.cpp
 * --------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the word ladder problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "console.h"
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
using namespace std;


Vector<string> wordLadder(string source, string dest);
void print(const Vector<string> & vec);
int main() {
    cout << "This program creates ladder between two words!" << endl;
    while (true) {
        string source = getLine("The source word (Enter to exit): ");
        if (source == "") break;
        string dest = getLine("The destination word: ");
        Vector<string> ladder = wordLadder(source, dest);
        if (ladder.size() == 1)
            cout << "There is no ladder between those two words!!" << endl;
        else
            print(ladder);
    }
	return 0;
}

void print(const Vector<string> & vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

Vector<string> wordLadder(string source, string dest) {
    Vector<string> ladder;
    ladder += source;
    Lexicon english("EnglishWords.dat");
    if (source.length() != dest.length() || !english.contains(source) || !english.contains(dest))
        return ladder;
    Queue< Vector<string> > ladders;
    Lexicon usedWords;
    usedWords.add(source);
    ladders.enqueue(ladder);

    while (!ladders.isEmpty()) {
        Vector<string> words = ladders.dequeue();
        string currWord = words[words.size() - 1];
        if (currWord == dest) {
            return words;
        } else {
            for (int i = 0; i  <  currWord.length(); i++) {
                string str = currWord;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    str[i] = ch;
                    if(english.contains(str) && !usedWords.contains(str)) {
                        usedWords.add(str);
                        Vector<string> newLadder = words;
                        newLadder += str;
                        ladders.enqueue(newLadder);
                    }
                }
            }

        }

    }
    return ladder;
}
