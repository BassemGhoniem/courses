/*
 * File: complex.h
 * ---------------
 * This interface exports simple complex type
 */
#ifndef _COMPLEX_H
#define _COMPLEX_H

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
};

#endif
