/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the coin-flipping problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

int main() {
    int heads = 0, count =  0;
    while (heads != 3) {
        count++;
        if (randomChance(0.5)) {
            cout << "Head" << endl;
            heads++;
        } else {
            cout << "Tail" << endl;
            heads = 0;
        }
    }
    cout << "It took " << count << " times to get 3 consecutive heads" << endl;
    return 0;
}
