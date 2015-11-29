/*
 * File: complex.cpp
 * -----------------
 *  This program compute the difference and sum
 *  of two complex numbers
 */

#include <iostream>
#include <cmath>
#include "complex.h"
using namespace std;

Complex::Complex (int r , int i ) {
    cout << endl << "Constructor Called!" << endl;
    real = r;
    imaj = i;
}
Complex::Complex(int x) {
    cout << endl << "Constructor Called!" << endl;
    real = imaj = x;
}
Complex::~Complex() {
    cout << "Deconstructor Called!" << endl;
}

float Complex::getReal() {
    return real;
}
float Complex::getImaj() {
    return imaj;
}
void Complex::setReal(float r) {
    real = r;
}
void Complex::setImaj(float i) {
    imaj = i;
}
void Complex::print() {
    cout << real << (imaj < 0 ? " - " : " + ") << abs(imaj) << "i" << endl;
}

Complex Complex::operator+(Complex c) {
    return Complex(real + c.real, imaj + c.imaj);
}
Complex Complex::operator-(Complex c) {
    return Complex(real - c.real, imaj - c.imaj);
}

bool Complex::operator>(Complex c) {
    return real > c.real; 
}

bool Complex::operator<(Complex c) {
    return real < c.real;
}
