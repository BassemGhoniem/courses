/*
 * File: stack.cpp
 * ---------------
 * This program implements stack class using array as underlying representation
 */

#include <iostream>
#include "stack.h"
using namespace std;

int Stack::count = 0;
Stack::Stack(int size) {
    cout << endl << "Constructor Called!" << endl;
    stk = new int[this->size = size];
    tos = 0;
    count++;
}
Stack::Stack(Stack &stack) {
    cout << endl << "Copy constructor Called!" << endl;
    tos = stack.tos;
    stk = new int[this->size = stack.size];
    for (int i = 0; i < tos; i++)
        stk[i] = stack.stk[i];
    count++;
}
    
Stack::~Stack() {
    cout << endl << "Deconstructor Called!" << endl;
    for (int i = 0; i < tos; i++)
        stk[i] = -1;
    delete[] stk;
}

bool Stack::push(int x) {
    if (isFull()) {
        cout << "Can't push, Stack is Full!!" << endl;
        return false;
    } else {
        stk[tos++] = x;
        return true;
    }
}

bool Stack::pop(int & item) {
    if (isEmpty()) {
        cout << "The stack is empty!" << endl;
        return false;
    } else { 
        item = stk[--tos];
        return true;
    } 
}

bool Stack::isEmpty() {
    return tos == 0;
}

bool Stack::isFull() {
    return tos == size;
}

int Stack::getCount() {
    return count;
}

void viewContent(Stack stack) {
    cout << endl << "The stack contains: ";
    for (int i = 0; i < stack.tos; i++)
        cout << stack.stk[i] << " ";
    cout << endl;
}
/*
void viewContent(Stack &stack) {
     cout << endl << "The stack contains: ";
    for (int i = 0; i < stack.tos; i++)
        cout << stk[i] << " ";
    cout << endl;
}
*/
