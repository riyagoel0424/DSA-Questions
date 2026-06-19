#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
    Node* header;
    int size;
    int count;

public:
    LinkedList(int s) : size(s), count(0), head(nullptr) {
        header = new Node{0, nullptr}; // Header node to keep track of count
    }

    ~LinkedList() {
        clear();
        delete header;
    }

    bool insert(int num) {
        if (count < size) {
            Node* newNode = new Node{num, head};
            head = newNode;
            count++;
            header->data = count; // Update header node with count
            return false;
        }
        return true;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        count = 0;
        header->data = count; // Reset count in header
    }

    int getCount() const {
        return header->data; // Retrieve count from header node
    }
};

#endif
