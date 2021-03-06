/*
 * File: complex.cpp
 * -----------------
 *  This program compute the difference and sum
 *  of two complex numbers
 */

#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    private:
        float real, imaj;
    public:
        Complex (int r = 0, int i = 0) {
            cout << endl << "Constructor Called!" << endl;
            real = r;
            imaj = i;
        }
        Complex(int x) {
            cout << endl << "Constructor Called!" << endl;
            real = imaj = x;
        }
        ~Complex() {
            cout << "Deconstructor Called!" << endl;
        }
        
        float getReal() {
            return real;
        }
        float getImaj() {
            return imaj;
        }
        void setReal(float r) {
            real = r;
        }
        void setImaj(float i) {
            imaj = i;
        }
        void print() {
            cout << real << (imaj < 0 ? " - " : " + ") << abs(imaj) << "i" << endl;
        }
};

Complex add(Complex C1, Complex C2){
    Complex result;
    result.setReal(C1.getReal() + C2.getReal());
    result.setImaj(C1.getImaj() + C2.getImaj());
    return result;
}

Complex sub(Complex C1, Complex C2){
    Complex result;
    result.setReal(C1.getReal() - C2.getReal());
    result.setImaj(C1.getImaj() - C2.getImaj());
    return result;
}

Complex readComplex();
int main (){
    Complex c1, c2;
    cout << "This program add or sub two Complex Numbers:-" << endl;
    c1 = readComplex();
    c2 = readComplex();
    int i = 0;
    do {
        cout << endl << "1 Add." << endl;
        cout << "2 Sub." << endl;
        cout << "3 Exit." << endl;
        cout << "Your Choice: ";
        cin >> i;
        switch(i) {
            case 1:
                cout << "Result = ";
                add(c1, c2).print();
                break;
            case 2:
                cout << "Result = ";
                sub(c1, c2).print();
                break;
            case 3:
                cout <<"Good Bye" << endl;
        }
    } while (i != 3);
}

Complex readComplex() {
      Complex c;
      cout << endl << "Real term = ";
      int value;
      cin >> value;
      c.setReal(value);
      cout << "Imaj term = ";
      cin >> value;
      c.setImaj(value);
      return c;
}
