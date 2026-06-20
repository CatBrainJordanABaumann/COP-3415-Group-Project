#pragma once

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T data = T(), Node<T>* next = nullptr);
};