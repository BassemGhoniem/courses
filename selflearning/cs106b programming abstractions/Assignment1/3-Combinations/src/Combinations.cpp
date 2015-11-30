/*
 * File: Combinations.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the recursive combinations problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
using namespace std;

unsigned combination(unsigned n, unsigned r);
int main() {
   cout << "This program count C(n, r)" << endl;
   int n = getInteger("n: ");
   int r = getInteger("r: ");
   cout << "C(" << n << ", " << r << ") = " << combination(n, r) << endl;
   return 0;
}

unsigned combination(unsigned n, unsigned r) {
    if (n == r || r == 0)
        return 1;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}
