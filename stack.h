#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
    int* data;
    int size;
    int top;

public:
    Stack(int s) : size(s), top(-1) { data = new int[size]; }
    ~Stack() { delete[] data; }

    bool insert(int num) {
        if (top < size - 1) {
            data[++top] = num;
            return false;
        }
        return true;
    }

    void clear() { top = -1; }
};

#endif
