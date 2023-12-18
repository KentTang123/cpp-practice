#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include<iostream>
#include"Node.h"


class DoublyLinkedlist {
public:
    DoublyLinkedlist();
    ~DoublyLinkedlist();
    int getSize();
    void traversal();
    void push_back(int in);
    void push_front(int in);
    void insertAt(int pos,int index);
    void deleteAt(int pos);
    int searchfirst(int in);
    int searchLast(int in);
    int getAt(int pos);
    int pop_back();
    int pop_front();

private:
    Node* head;
};


#endif