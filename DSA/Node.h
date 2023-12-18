#ifndef NODE_H
#define NODE_H

#include<iostream>

using namespace std;

class Node {
public:
    Node();
    Node(int in);
    ~Node();
    void setIndex(int in);
    void setPrev(Node* p);
    void setNext(Node* n);
    int getIndex();
    Node* getPrev();
    Node* getNext();
    void clear();
private:
    int index;
    Node* prev;
    Node* next;
};




#endif