#include <iostream>
#include "complex.h"
using namespace std;

Complex readComplex();
int getOption();
void respond(int i, Complex c1, Complex c2);

int main (){
    Complex c1, c2;
    cout << "This program add or sub two Complex Numbers:-" << endl;
    c1 = readComplex();
    c2 = readComplex();
    int i = 0;
    do {
        i = getOption();
        respond(i, c1, c2);   
    } while (i != 17);
}

Complex readComplex() {
      Complex c;
/*
      cout << endl << "Real term = ";
      int value;
      cin >> value;
      c.setReal(value);
      cout << "Imaj term = ";
      cin >> value;
      c.setImaj(value);
*/
      cin >> c;
      return c;
}
int getOption() {
    int option;
    string menu[] = { "1 Add.", "2 Sub.", "3 C1 > C2? ", "4 C1 < C2? ", "5 C1 == C2? ",  "6 C1 != C2? ",
                      "7 C1 += C2 ", "8 C1 = C2 ", "9 C1 -= C2 ", "10 C1 + X ", "11 X + C1 ", "12 C1 - X",
                      "13 X - C1", "14 C2++" , "15 ++C2", "16 float(C2)", "17 EXIT"};
    cout << endl;
    for (int i = 0; i < 17; i++)
        cout << menu[i] << endl;
    cout << "Your Choice: ";
    cin >> option;
    cout << boolalpha;
    return option;
}
void respond(int i, Complex c1, Complex c2) {
    int value;
    switch(i) {
            case 1:
                cout << "Result = " << c1 + c2;
                break;
            case 2:
                cout << "Result = " << c1 - c2;
                break;
            case 3:
                cout << (c1 > c2) << endl;
                break;
            case 4:
                cout << (c1 < c2) << endl;
                break;
            case 5:
                cout << (c1 == c2) << endl;
                break;
            case 6:
                cout << (c1 != c2) << endl;
                break;
            case 7: 
                cout << "result = " <<  (c1 += c2);
                cout << "C1= " << c1;
                cout << "C2= " << c2;
                break;
            case 8:
                cout << "C1= " << (c1 = c2);
                cout << "C2= " << c2;
                break;
            case 9:
                cout << "C1 = " << (c1 -= c2);
                cout << "C2 = " << c2;
                break;
            case 10:
                cout << "X = ";
                cin >> value;
                cout << "result = " << (c1 + value);
                break;
            case 11:
                cout << "X = ";
                cin >> value;
                cout << "result = " << (value + c1);
                break;
            case 12:
                cout << "X = ";
                cin >> value;
                cout << "result = " << (c1 - value);
                break;
            case 13:
                cout << "X = ";
                cin >> value;
                cout << "result = " << (value - c1);
                break;
            case 14:
                cout << "C2 = " << c2++;
                cout << "C2 = " << c2;
                break;
            case 15:
                cout << "C2 = " << ++c2;
                cout << "C2 = " << c2;
                break;
            case 16:
                cout << "result = " << float(c2) << endl;
                break;
            case 17:
                cout <<"Good Bye" << endl;
                break;
        }
}
