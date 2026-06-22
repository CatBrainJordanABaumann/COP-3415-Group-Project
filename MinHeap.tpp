#pragma once

#include "MinHeap.h"
#include <iostream>
#include <cstring>

template <typename T>
MinHeap<T>::MinHeap(int capacity) :
    data(new T[capacity]),
    size(0), capacity(capacity) { }

template <typename T>
MinHeap<T>::MinHeap(T* data, int size, int capacity) :
    data(new T[capacity]),
    size(size), capacity(capacity) {
    std::memcpy(this->data, data, size * sizeof(T));
    for (int i = parent(size - 1); i >= 0; i--)
        percolateDown(i);
}

template <typename T>
MinHeap<T>::~MinHeap() {
    delete[] data;
}

template <typename T>
int MinHeap<T>::parent(int index) {
    return (index - 1) / 2;
}

template <typename T>
int MinHeap<T>::leftChild(int index) {
    return index * 2 + 1;
}

template <typename T>
int MinHeap<T>::rightChild(int index) {
    return index * 2 + 2;
}

template <typename T>
void MinHeap<T>::percolateDown(int index) {
    int leftIndex = leftChild(index),
        rightIndex = rightChild(index);

    if (leftIndex >= size ||
        (!(data[leftIndex] < data[index]) &&
        (rightIndex >= size || !(data[rightIndex] < data[index]))))
        return;

    int minIndex = (rightIndex >= size || data[leftIndex] < data[rightIndex])
        ? leftIndex : rightIndex;
    
    std::swap(data[index], data[minIndex]);
    percolateDown(minIndex);
}

template <typename T>
void MinHeap<T>::percolateUp(int index) {
    int parentIndex = parent(index);
    if (parentIndex < 0 || index <= 0 ||
        !(data[index] < data[parentIndex]))
        return;
    
    std::swap(data[index], data[parentIndex]);
    percolateUp(parentIndex);
}

template <typename T>
bool MinHeap<T>::empty() const {
    return size <= 0;
}


template <typename T>
void MinHeap<T>::push(T item) {
    if (size >= capacity) {
        std::cout << "Heap Overflow" << std::endl;
        throw "Heap Overflow";
    }
    data[++size - 1] = item;
    percolateUp(size - 1);
}

template <typename T>
T MinHeap<T>::pop() {
    if (size <= 0) {
        std::cout << "Heap Underflow" << std::endl;
        throw "Heap Underflow";
    }
    std::swap(data[0], data[--size]);
    percolateDown(0);
    return data[size];
}

template <typename T>
T MinHeap<T>::peek() const {
    return data[0];
}


template <typename T>
void MinHeap<T>::print() const {
    if (empty())
        return;
    std::cout << data[0];
    for (int i = 1; i < size; i++)
        std::cout << ' ' << data[i];
}