#ifndef HEAP_H
#define HEAP_H
#include <climits>
#include <iostream>

class MinHeap {
public:
    MinHeap(int capacity);
    ~MinHeap();
    void insert(int vertex, int key);
    int extractMin();
    void decreaseKey(int vertex, int newKey);
    bool isInMinHeap(int vertex);
    bool isEmpty();

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx);
    void swap(int& a, int& b); // swap two integers
};

MinHeap::MinHeap(int capacity) { // setup arrays
    this -> capacity = capacity;
    size = 0;
    heapArray = new int[capacity];
    keyArray = new int[capacity];
    position = new int[capacity];

    for (int i = 0; i < capacity; ++i) {
        keyArray[i] = INT_MAX;  // Default all weights to infinity
        position[i] = i;        // Set default position
    }
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

void MinHeap::insert(int vertex, int key) {
    size++;
    int idx = size - 1;
    heapArray[idx] = vertex;
    keyArray[vertex] = key;
    position[vertex] = idx;

    while (idx != 0 && keyArray[heapArray[(idx - 1) / 2]] > keyArray[heapArray[idx]]) { // Move the new element up to maintain the heap property
        int parentIdx = (idx - 1) / 2;
        swap(heapArray[idx], heapArray[parentIdx]);
        swap(position[heapArray[idx]], position[heapArray[parentIdx]]);
        idx = parentIdx;
    }
}

int MinHeap::extractMin() {
    if (size <= 0) return -1;

    int root = heapArray[0]; // Top of the heap
    int lastNode = heapArray[size - 1]; // Last inserted vertex
    heapArray[0] = lastNode; // Move last to the top
    position[root] = size - 1;
    position[lastNode] = 0;

    size--;
    minHeapify(0); // Restore the heap property

    return root;
}

void MinHeap::decreaseKey(int vertex, int newKey) {
    int idx = position[vertex];
    keyArray[vertex] = newKey;

    while (idx != 0 && keyArray[heapArray[(idx - 1) / 2]] > keyArray[heapArray[idx]]) { // Move up while the new key is smaller than parent's key
        int parentIdx = (idx - 1) / 2;
        swap(heapArray[idx], heapArray[parentIdx]);
        swap(position[heapArray[idx]], position[heapArray[parentIdx]]);
        idx = parentIdx;
    }
}

bool MinHeap::isInMinHeap(int vertex) {
    return position[vertex] < size;
}

bool MinHeap::isEmpty() {
    return size == 0;
}

void MinHeap::minHeapify(int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int smallest = idx;

    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]]) {
        smallest = left;
    }
    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]]) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(heapArray[idx], heapArray[smallest]);
        swap(position[heapArray[idx]], position[heapArray[smallest]]);
        minHeapify(smallest); // Recursively fix affected subtree
    }
}

void MinHeap::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

#endif