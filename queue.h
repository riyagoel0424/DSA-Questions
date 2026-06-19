#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue {
    int* data;
    int size;
    int front, rear, count;

public:
    Queue(int s) : size(s), front(0), rear(-1), count(0) { data = new int[size]; }
    ~Queue() { delete[] data; }

    bool insert(int num) {
        if (count < size) {
            rear = (rear + 1) % size;
            data[rear] = num;
            count++;
            return false;
        }
        return true;
    }

    void clear() { front = 0; rear = -1; count = 0; }
};

#endif
