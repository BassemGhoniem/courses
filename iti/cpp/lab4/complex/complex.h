/*
 * File: complex.h
 * ---------------
 * This interface exports simple complex type
 */
#ifndef _COMPLEX_H
#define _COMPLEX_H
#include <iostream>
class Complex {
    private:
        float real, imaj;
    public:
        Complex (int r = 0, int i = 0); 
        Complex(int x);
        ~Complex();
        
        float getReal();
        float getImaj();
        void setReal(float r);
        void setImaj(float i);
        void print();
        
        Complex operator+(Complex c);
        Complex operator-(Complex c);
        bool operator>(Complex c);
        bool operator<(Complex c);
        
        /* lab 4 operator overloading */
        Complex operator+(int x);
        Complex operator-(int x);
        friend Complex operator+(int x, Complex c);
        friend Complex operator-(int x, Complex c);

        Complex operator+=(Complex c);
        Complex operator-=(Complex c);
        Complex operator=(Complex c);
        
        bool operator==(Complex c);
        bool operator!=(Complex c);
        
        Complex operator++();
        Complex operator++(int);
        Complex operator--();
        Complex operator--(int);
        operator float();
        Complex operator()(int r, int i);
        friend std::ostream &operator<<(std::ostream &output, Complex c);
        friend std::istream &operator>>(std::istream &input, Complex &c);
        
};

#endif
