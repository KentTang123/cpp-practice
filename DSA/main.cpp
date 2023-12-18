#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "Node.h"
#include "DoublyLinkedlist.h"
#include "Sort.h"


int main(int, char**) {

    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(7);

    while (true) {
        cout << "Please choose want kind of DSA example you want to use " << endl;
        cout << "Enter 0 to exit the program\n"
            "Enter 1 to use functions of DoublyLinkedlist\n"
            "Enter 2 to observe different sort method cost time \n";

        int input;
        cin >> input;

        if (input == 0)
            break;

        switch (input) {

        case 1:
        {
            cout << "You are now using DoublyLinkedlist\n"
                "Enter 0 to stop using DoublyLinkedlist\n"
                "Enter 1 to traversal the list\n"
                "Enter 2 to push_back an index\n"
                "Enter 3 to push_front an index\n"
                "Enter 4 to insert index at given position\n"
                "Enter 5 to delete index at given position\n"
                "Enter 6 to search the first instant of an index\n"
                "Enter 7 to search the last instant of an index\n"
                "Enter 8 to get index of a given position\n"
                "Enter 9 to pop_back the list\n"
                "Enter 10 to pop_front the list\n"
                "Enter 11 to get the size of the list\n";
            int in, index, pos;
            DoublyLinkedlist* dll = new DoublyLinkedlist();

            while (true) {
                cin >> in;
                if (in == 0) {
                    break;
                }switch (in) {
                case 1:
                    dll->traversal();
                    break;
                case 2:
                    cout << "Enter an index: ";
                    cin >> index;
                    dll->push_back(index);
                    break;
                case 3:
                    cout << "Enter an index: ";
                    cin >> index;
                    dll->push_front(index);
                    break;
                case 4:
                    cout << "Enter an index to insert and its position: ";
                    cin >> index >> pos;
                    dll->insertAt(pos, index);
                    break;
                case 5:
                    cout << "Enter an position of index to delete: ";
                    cin >> pos;
                    dll->deleteAt(pos);
                    break;
                case 6:
                    cout << "Enter a index to search its first instant:";
                    cin >> index;
                    cout << "The first instant of the index is at position " << dll->searchfirst(index) << endl;
                    break;
                case 7:
                    cout << "Enter a index to search its last instant:";
                    cin >> index;
                    cout << "The first instant of the index is at position " << dll->searchLast(index) << endl;
                    break;
                case 8:
                    cout << "Enter a position of an index you want to get: ";
                    cin >> pos;
                    dll->getAt(pos);
                    break;
                case 9:
                    dll->pop_back();
                    break;
                case 10:
                    dll->pop_front();
                    break;
                case 11:
                    cout << "The size of the list is " << dll->getSize() << endl;
                    break;
                default:
                    cout << "Invalid input" << endl;
                    break;
                }
            }
            delete dll;
        }
        break;
        case 2:
        {
            int* arr = new int[10000];
            int input;
            chrono::steady_clock::time_point t1;
            chrono::steady_clock::time_point t2;

            cout << "You are now observing how much time different sort method takes to sort 10000 element\n"
                "Enter 0 to stop\n"
                "Enter 1 to use bubble sort\n"
                "Enter 2 to use selection sort\n"
                "Enter 3 to use heap sort\n"
                "Enter 4 to use merge sort\n"
                "Enter 5 to use quick sort\n";

            while (true) {
                int size = 10000;
                setupArr(arr, size);

                cin >> input;
                if (input == 0) {
                    break;
                }
                switch (input) {
                case 1:
                    t1 = std::chrono::steady_clock::now();
                    BubbleSort(arr, size);
                    t2 = std::chrono::steady_clock::now();
                    cout << "The bubble sort took "
                        << 1.000000 * chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1000000
                        << "s.\n";
                    break;
                case 2:
                    t1 = std::chrono::steady_clock::now();
                    SelectionSort(arr, size);
                    t2 = std::chrono::steady_clock::now();
                    cout << "The selection sort took "
                        << 1.000000 * chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1000000
                        << "s.\n";
                    break;
                case 3:
                    t1 = std::chrono::steady_clock::now();
                    HeapSort(arr, size);
                    t2 = std::chrono::steady_clock::now();
                    cout << "The heap sort took "
                        << 1.000000 * chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1000000
                        << "s.\n";
                    break;
                case 4:
                    t1 = std::chrono::steady_clock::now();
                    MergeSort(arr, size);
                    t2 = std::chrono::steady_clock::now();
                    cout << "The merge sort took "
                        << 1.000000 * chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1000000
                        << "s.\n";
                    break;
                case 5:
                    t1 = std::chrono::steady_clock::now();
                    QuickSort(arr, 0, size - 1);
                    t2 = std::chrono::steady_clock::now();
                    cout << "The quick sort took "
                        << 1.000000 * chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1000000
                        << "s.\n";
                    break;

                default:
                    cout << "Invalid input" << endl;
                    break;
                }
            }
            delete[]arr;
        }
        break;
        default:
            cout << "Invalid input" << endl;
            break;
        }

    }

    cout << "Bye, from DSA!\n";
}




