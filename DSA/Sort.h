#ifndef SORT_H
#define SORT_H
#include <cstdlib>
#include <iostream>

inline void setupArr(int* arr, int size) {
    for (int i = 0;i < size;i++)
        arr[i] = rand() % 5000 + 2;
}

void printArr(int* arr, int size) {
    for (int i = 0;i < size;i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int BinarySearch_Iterative(int* arr, int size, int key) {
    int l = 0;
    int r = size - 1;

    int mid = (l + r) / 2;

    while (l <= r) {
        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] > key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }

        mid = (l + r) / 2;
    }

    return -1;
}

int BinarySearch_Recursive(int* arr, int key, int l, int r) {

    int mid = (l + r) / 2;

    if (l > r) {
        return -1;
    }

    if (arr[mid] == key) {
        return mid;
    }

    if (arr[mid] > key) {
        return BinarySearch_Recursive(arr, key, l, mid - 1);

    } else if (arr[mid] < key) {
        return BinarySearch_Recursive(arr, key, mid + 1, r);
    }

    return -1;
}

void BubbleSort(int* arr, int size) {
    for (int i = 0;i < size - 1;i++) {
        for (int j = 0;j < size - 1 - i;j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void SelectionSort(int* arr, int size) {
    int temp, index;
    for (int i = 0;i < size - 1;i++) {
        temp = arr[i];
        index = i;

        for (int j = i + 1;j < size;j++)
            if (arr[j] < arr[index])
                index = j;

        arr[i] = arr[index];
        arr[index] = temp;
    }
}

int* MergeSort(int* arr, int size) {
    if (size == 1) {
        return arr;
    }

    int* l = new int[size / 2];
    int* r = new int[size - size / 2];

    for (int i = 0;i < size / 2;i++)
        l[i] = arr[i];

    for (int i = 0;i < (size - size / 2);i++)
        r[i] = arr[size / 2 + i];

    l = MergeSort(l, size / 2);
    r = MergeSort(r, size - size / 2);

    int i = 0, j = 0;

    while (i + j < size) {
        if (i == size / 2) {
            arr[i + j] = r[j];
            j++;
        } else if (j == size - size / 2) {
            arr[i + j] = l[i];
            i++;
        } else if (l[i] <= r[j]) {
            arr[i + j] = l[i];
            i++;
        } else if (l[i] > r[j]) {
            arr[i + j] = r[j];
            j++;
        }
    }
    delete[]l;
    delete[]r;
    return arr;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int getMaxchild(int* arr, int node, int size) {
    if ((node + 1) * 2 <= size - 1) {
        if (arr[(node + 1) * 2 - 1] >= arr[(node + 1) * 2]) {
            return (node + 1) * 2 - 1;
        } else {
            return (node + 1) * 2;
        }
    } else if ((node + 1) * 2 - 1 <= size - 1) {
        return (node + 1) * 2 - 1;
    } else {
        return node;
    }
}

void Heapify(int* arr, int size) {
    int h = static_cast<int>(log2(size));

    for (int i = static_cast<int>(pow(2, h)) - 1;i >= 0;i--) {
        int x = i;

        while (x < size - 1) {
            if (arr[getMaxchild(arr, x, size)] <= arr[x]) {
                x = size - 1;
            }

            if (arr[getMaxchild(arr, x, size)] > arr[x]) {
                int t = getMaxchild(arr, x, size);
                swap(arr[getMaxchild(arr, x, size)], arr[x]);

                x = t;
            }
        }

    }
}


void HeapSort(int* arr, int size) {
    Heapify(arr, size);

    for (int i = 0;i < size - 1;i++) {
        swap(arr[0], arr[size - 1 - i]);
        int x = 0;

        while (x < size - 1 - i) {
            if (arr[getMaxchild(arr, x, size - 1 - i)] <= arr[x]) {
                x = size - 1 - i;
            } else if (arr[getMaxchild(arr, x, size - 1 - i)] > arr[x]) {
                int t = getMaxchild(arr, x, size - 1 - i);
                swap(arr[getMaxchild(arr, x, size - 1 - i)], arr[x]);
                x = t;
            }
        }
    }
}


int partition(int* arr, int l, int r) {

    int i = l + 1, j = r;

    int pivot = arr[l];

    while (true) {
        if (i > j) {
            break;
        }

        while (arr[i] <= pivot) {
            if (i > j)
                break;
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < j)
            swap(arr[i],arr[j]);
    }

    swap(arr[l],arr[j]);

    return j;
}


void QuickSort(int* arr, int l, int r) {

    if (l < r) {
        int x = partition(arr, l, r);

        if (x > l)
            QuickSort(arr, l, x - 1);
        if (r > x)
            QuickSort(arr, x + 1, r);
    }
    return;
}

#endif