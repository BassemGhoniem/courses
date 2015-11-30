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


Queue<string> wordLadder(string source, string dest);

int main() {
	// [TODO: fill in the code]
	return 0;
}


Queue<string> wordLadder(string source, string dest) {
    Lexicon english("EnglishWords.dat");
    Queue< Vector<string> > ladders;
    Vector<string> ladder += source;
    set<string> usedWords;
    ladders.enqueue(source);
    ladders.enqueue(ladder);
    while (!ladders.isEmpty()) {
        Vector<string> words = ladder.dequeue();
        if (word[words.size() - 1] == dest) {
            return ladder;
        } else {
            string str = words[words.size() - 1];
            for (char ch = str[0]; ch <= 'z'; ch++) {
                for ()
            }

        }

    }
}
