/*
 * File: stack.h
 * --------------
 * This interface exports stack data structure
 */

#ifndef _STACK_H
#define _STACK_H
#include <iostream>
using namespace std;

template <typename T>
class Stack;
template <typename T>
void viewContent(Stack<T> stack);

template <typename T>
class Stack {
    public:
        Stack(int size = 10);
        Stack(Stack<T> &stack);
        ~Stack();

        bool push(T value);
        bool pop(T &value);
        bool isEmpty();
        bool isFull();
        static int getCount();
        friend void viewContent<>(Stack stack);
        
        Stack<T> operator=(Stack<T> s);
        Stack<T> operator+=(int ext);
        Stack<T> operator+(Stack<T> s);
    private:
        int tos, size;
        T *stk;
        static int count;
};
#include "stack.cpp"
#endif
