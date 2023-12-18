#include "DoublyLinkedlist.h"



DoublyLinkedlist::DoublyLinkedlist() :head(nullptr) {

}

DoublyLinkedlist::~DoublyLinkedlist() {
    delete this->head;
}

int DoublyLinkedlist::getSize() {
    if (head == nullptr)
        return 0;

    int size = 0;

    Node* temp = head;
    while (temp != nullptr) {
        size++;
        temp = temp->getNext();
    }
    return size;
}

void DoublyLinkedlist::traversal() {
    if (this->getSize() == 0) {
        cout << "There is no element in the list" << endl;
        return;
    }

    Node* temp = head;

    cout << temp->getIndex() << " ";

    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
        cout << temp->getIndex() << " ";
    }
    cout << endl;
}

void DoublyLinkedlist::push_back(int in) {
    if (head == nullptr) {
        head = new Node(in);
        return;
    }

    Node* temp = head;
    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
    }

    Node* newNode = new Node(in);

    temp->setNext(newNode);
    newNode->setPrev(temp);
}

void DoublyLinkedlist::push_front(int in) {
    Node* newNode = new Node(in);

    Node* temp = head;

    newNode->setNext(temp);
    head->setPrev(newNode);

    head = newNode;
}

void DoublyLinkedlist::insertAt(int pos, int index) {
    if (pos > (this->getSize())) {
        cout << "Out of range\n";
        return;
    } else if (pos == this->getSize()) {
        this->push_back(index);
        return;
    } else if (pos == 0) {
        this->push_front(index);
        return;
    }

    Node* temp = head;
    Node* newNode = new Node(index);

    for (int i = 1;i < pos;i++)
        temp = temp->getNext();

    newNode->setNext(temp->getNext());
    newNode->setPrev(temp);

    temp->getNext()->setPrev(newNode);
    temp->setNext(newNode);


}


void DoublyLinkedlist::deleteAt(int pos) {
    if (pos > (this->getSize() - 1)) {
        cout << "Out of range\n";
        return;
    } else if (pos == 0) {
        Node* temp = head;
        head = temp->getNext();
        head->setPrev(nullptr);
        delete temp;
        return;
    } else if (pos == (this->getSize() - 1)) {
        Node* temp = head;

        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }

        temp->getPrev()->setNext(nullptr);
        delete temp;
        return;
    }

    Node* temp = head;

    for (int i = 0;i < pos;i++)
        temp = temp->getNext();

    temp->getPrev()->setNext(temp->getNext());
    temp->getNext()->setPrev(temp->getPrev());

    temp->clear();

}

int DoublyLinkedlist::searchfirst(int in) {

    int pos = 0;
    Node* temp = head;
    while (true) {
        if (temp->getIndex() == in) {
            break;
        }

        temp = temp->getNext();
        pos++;
        if (pos == this->getSize()) {
            cout << "Not found" << endl;
            return -1;
        }
    }

    return pos;
}

int DoublyLinkedlist::searchLast(int in) {
    
    int pos = this->getSize() - 1;
    Node* temp = head;
    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
    }

    while (true) {
        if (temp->getIndex() == in) {
            break;
        }

        temp = temp->getPrev();
        pos--;
        if (pos == -1) {
            cout << "Not found" << endl;
            return -1;
        }
    }

    return pos;
}

int DoublyLinkedlist::getAt(int pos) {
    Node* temp = head;

    for (int i = 0;i < pos;i++)
        temp = temp->getNext();

    return temp->getIndex();
}

int DoublyLinkedlist::pop_back() {
    int r = this->getAt(this->getSize() - 1);
    this->deleteAt(this->getSize() - 1);
    return r;
}

int DoublyLinkedlist::pop_front() {
    int r = head->getIndex();
    this->deleteAt(0);
    return r;
}
