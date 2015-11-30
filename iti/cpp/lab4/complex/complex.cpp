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
//    cout << endl << "Constructor Called!" << endl;
    real = r;
    imaj = i;
}
Complex::Complex(int x) {
  //  cout << endl << "Constructor Called!" << endl;
    real = imaj = x;
}
Complex::~Complex() {
    //cout << "Deconstructor Called!" << endl;
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
    /* lab 4 operator overloading */
Complex Complex::operator+(int x) {
    return Complex(real + x, imaj);
}
Complex Complex::operator-(int x) {
    return Complex(real - x, imaj);
}

Complex operator+(int x, Complex c) {
    return Complex(c.real + x, c.imaj);
}

Complex operator-(int x, Complex c) {
    return Complex(x - c.real, c.imaj);
}


Complex Complex::operator+=(Complex c) {
    real += c.real;
    imaj += c.imaj;
    return *this;
}
Complex Complex::operator-=(Complex c) {
    real -= c.real;
    imaj -= c.imaj;
    return *this;
}

Complex Complex::operator=(Complex c) {
    real = c.real;
    imaj = c.imaj;
    return *this;
}


bool Complex::operator==(Complex c) {
    return real == c.real;
}

bool Complex::operator!=(Complex c) {
    return ! (*this == c);
}

Complex Complex::operator++() {
    real++;
    return *this;
}
Complex Complex::operator++(int) {
    Complex tmp(*this);
    real++;
    return tmp;
}
Complex Complex::operator--() {
    real--;
    return *this;
}

Complex Complex::operator--(int) {
    Complex tmp(*this);
    real--;
    return tmp;
}

Complex::operator float() {
    return real;
}    
    
Complex Complex::operator()(int r, int i) {
    real = r;
    imaj = i;
    return *this;
}
ostream &operator<<(ostream &output, Complex c) {
    output << c.real << (c.imaj < 0 ? " - " : " + ") << abs(c.imaj) << "i" << endl;
    return output;
}
istream &operator>>(istream &input, Complex &c) {
    cout << "Enter the terms of complex: " ;
    input >> c.real >> c.imaj;
    return input;
}

