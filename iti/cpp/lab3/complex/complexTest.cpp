#include <iostream>
#include "complex.h"
using namespace std;

Complex readComplex();
int main (){
    Complex c1, c2;
    cout << "This program add or sub two Complex Numbers:-" << endl;
    c1 = readComplex();
    c2 = readComplex();
    int i = 0;
    do {
        cout << boolalpha;
        cout << endl << "1 Add." << endl;
        cout << "2 Sub." << endl;
        cout << "3 C1 > C2? " << endl;
        cout << "4 C1 < C2? " << endl;
        cout << "5 Exit." << endl;
        cout << "Your Choice: ";
        cin >> i;
        switch(i) {
            case 1:
                cout << "Result = ";
                (c1 + c2).print();
                break;
            case 2:
                cout << "Result = ";
                (c1 - c2).print();
                break;
            case 3:
                cout << (c1 > c2) << endl;
                break;
            case 4:
                cout << (c1 < c2) << endl;
                break;
            case 5:
                cout <<"Good Bye" << endl;
                break;
        }
    } while (i != 5);
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
