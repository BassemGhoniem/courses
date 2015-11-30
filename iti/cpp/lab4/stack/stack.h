/*
 * File: stack.h
 * --------------
 * This interface exports stack data structure
 */

#ifndef _STACK_H
#define _STACK_H

class Stack {
    public:
        Stack(int size = 10);
        Stack(Stack &stack);
        ~Stack();

        bool push(int value);
        bool pop(int &value);
        bool isEmpty();
        bool isFull();
        static int getCount();
        friend void viewContent(Stack stack);
//        friend void viewContent(Stack &stack);
        
        Stack operator=(Stack s);
        Stack operator+=(int ext);
        Stack operator+(Stack s);
    private:
        int tos, size, *stk;
        static int count;
};

#endif
