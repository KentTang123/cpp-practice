#include "Node.h"



Node::Node() :index(NULL), prev(nullptr), next(nullptr) {
}

Node::Node(int in) :index(in), prev(nullptr), next(nullptr) {

}

Node::~Node() {
    
}

void Node::setIndex(int in) {
    this->index = in;
}

void Node::setPrev(Node* p) {
    this->prev = p;
}

void Node::setNext(Node* n) {
    this->next = n;
}

int Node::getIndex() {
    return this->index;
}

Node* Node::getPrev() {
    return this->prev;
}

Node* Node::getNext() {
    return this->next;
}

void Node::clear() {
    delete this;
}

