#ifndef CHAINING_H
#define CHAINING_H

#include <iostream>

struct CLLNode
{
    CLLNode() : next(nullptr), data(0) {}
    CLLNode(int d) : next(nullptr), data(d) {}
    ~CLLNode() {}

    int data;
    CLLNode* next;
};

class CLList
{
private:
    int length;
    CLLNode* head;

public:
    CLList();
    ~CLList();

    int getLength() const;
    bool search(int val) const;
    void insertAtBeg(int val);
    void insertAtIndex(int val, int index);
    void insertAtEnd(int val);
    void deleteAtBeg();
    void deleteAtIndex(int index);
    void deleteAtEnd();
    void display() const;
    CLLNode* getHead() const;
};

#endif // CIRCULAR_SINGLY_LINKED_LIST_H
