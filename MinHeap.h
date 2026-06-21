#pragma once

constexpr int DEFAULT_MAX_HEAP_SIZE = 1000;

template <typename T>
class MinHeap
{
private:
    T* data;
    int size, capacity;

    static int parent(int index);
    static int leftChild(int index);
    static int rightChild(int index);

    void percolateDown(int index);
    void percolateUp(int index);

public:
    MinHeap(int capacity = DEFAULT_MAX_HEAP_SIZE);
    MinHeap(T* data, int size, int capacity = DEFAULT_MAX_HEAP_SIZE);
    
    bool empty() const;

    void push(T item);
    T pop();
    T peek() const;

    void print() const;
};