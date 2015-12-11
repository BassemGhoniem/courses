/*
 * File : StackTest.cpp
 * --------------------
 * This program tests the stack class which implemented vi stack.h interface
 */


#include <iostream>
#include "stack.h"
using namespace std;
int main() {
    cout << boolalpha << "This program emulate the stack functionality!" << endl;
    cout << "Please enter the stack size? " ;
    int size, choice;
    cin >> size;
    Stack<int> s(size);
    do {
        cout << endl;
        cout << "1 push" << endl;
        cout << "2 pop"  << endl;
        cout << "3 is Empty?" << endl;
        cout << "4 is Full?" << endl;
        cout << "5 View Content" << endl;
        cout << "6 Objects counter" << endl;
        cout << "7 Extent the size" << endl;
        cout << "8 Exit!" << endl;

        cout << endl << "Your Choice? ";
        cin >> choice;
        
        int value;
        switch (choice) {
            case 1:
                cout << "Value to push? " ;
                cin >> value;
                s.push(value);
                break;
            case 2:
                if(s.pop(value))
                    cout << value << " poped!" << endl;
                break;
            case 3:
                cout << s.isEmpty() << endl;
                break;
            case 4:
                cout << s.isFull() << endl;
                break;
            case 5:
                viewContent(s);
                break;
            case 6:
                cout << endl << "Objects created: " << Stack<int>::getCount() << endl;
                break;
            case 7:
                cout << "extend by: " ;
                int x;
                cin >> x;
                s += x;
            case 8:
                cout << "GOOD BYE!!" << endl;
                break;
        }
    } while (choice != 8);
}
