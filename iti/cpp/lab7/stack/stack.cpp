/*
 * File: stack.cpp
 * ---------------
 * This program implements stack class using array as underlying representation
 */

#include <iostream>
using namespace std;

template<typename T>
int Stack<T>::count = 0;
template<typename T>
Stack<T>::Stack(int size) {
//    cout << endl << "Constructor Called!" << endl;
    stk = new T[this->size = size];
    tos = 0;
    count++;
}
template<typename T>
Stack<T>::Stack(Stack<T> &stack) {
  //  cout << endl << "Copy constructor Called!" << endl;
    tos = stack.tos;
    stk = new T[this->size = stack.size];
    for (int i = 0; i < tos; i++)
        stk[i] = stack.stk[i];
    count++;
}
template<typename T>
Stack<T>::~Stack() {
    //cout << endl << "Deconstructor Called!" << endl;
    for (int i = 0; i < tos; i++)
        stk[i] = -1;
    delete[] stk;
}

template<typename T>
bool Stack<T>::push(T x) {
    if (isFull()) {
        cout << "Can't push, Stack is Full!!" << endl;
        return false;
    } else {
        stk[tos++] = x;
        return true;
    }
}

template<typename T>
bool Stack<T>::pop(T & item) {
    if (isEmpty()) {
        cout << "The stack is empty!" << endl;
        return false;
    } else { 
        item = stk[--tos];
        return true;
    } 
}

template<typename T>
bool Stack<T>::isEmpty() {
    return tos == 0;
}

template<typename T>
bool Stack<T>::isFull() {
    return tos == size;
}

template<typename T>
int Stack<T>::getCount() {
    return count;
}

template<typename T>
void viewContent(Stack<T> stack){
    cout << endl << "The stack contains: ";
    for (int i = 0; i < stack.tos; i++)
        cout << stack.stk[i] << " ";
    cout << endl;
}

template<typename T>
Stack<T> Stack<T>::operator=(Stack<T> s) {
    delete[] stk;
    stk = new T[size = s.size];
    tos = s.tos;
    for (int i = 0; i < tos; i++)
        stk[i] = s.stk[i];
    return *this;
}

template<typename T>
Stack<T> Stack<T>::operator+=(int ext) {
    int* tmp = stk;
    stk = new T[size+=ext];
    for (int i = 0; i < tos; i++)
        stk[i] = tmp[i];
    delete[] tmp;
    return *this;
}

template<typename T>
Stack<T> Stack<T>::operator+(Stack<T> s) {
    Stack tmp(size + s.size);
    tmp.tos = tos + s.tos ;
    int i;
    for (i = 0; i < tos; i++)
        tmp.stk[i] = stk[i];
    for(int j = 0; j < s.tos; j++)
        tmp.stk[i++] = s.stk[j];
    return tmp;
}
