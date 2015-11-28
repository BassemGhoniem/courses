/*
 * File: stack.cpp
 * ---------------
 * This program implements stack class using array as underlying representation
 */

#include <iostream>
using namespace std;

class Stack {
    public :
        Stack(int s = 10) {
            cout << endl << "Constructor Called!" << endl;
            stk = new int[size = s];
            tos = 0;
        }
        ~Stack() {
            cout << endl << "Deconstructor Called!" << endl;
            delete[] stk;
        }
        bool push(int x) {
            if (isFull()) {
                cout << "Can't push, Stack is Full!!" << endl;
                return false;
            } else {
                stk[tos++] = x;
                return true;
            }
        }
        bool pop(int & item) {
            if (isEmpty()) {
                cout << "The stack is empty!" << endl;
                return false;
            } else { 
                item = stk[--tos];
                return true;
            } 
        }
        bool isEmpty() {
            return tos == 0;
        }
        bool isFull() {
            return tos == size;
        }
    private :
        int * stk, tos, size;
};


int main() {
    cout << boolalpha << "This program emulate the stack functionality!" << endl;
    cout << "Please enter the stack size? " ;
    int size, choice;
    cin >> size;
    Stack s(size);
    do {
        cout << endl;
        cout << "1 push" << endl;
        cout << "2 pop"  << endl;
        cout << "3 is Empty?" << endl;
        cout << "4 is Full?" << endl;
        cout << "5 Exit!" << endl;

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
                cout << "GOOD BYE!!" << endl;
                break;
        }
    } while (choice != 5);
}
