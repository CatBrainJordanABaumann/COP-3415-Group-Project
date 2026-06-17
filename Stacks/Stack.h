#ifndef STACK_H
#define STACK_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
class Stack
{

private:
    Node<T>* topNode;
    int stackSize;
public:
    Stack();
    void push(T value);
    void pop();
    T peek();
    bool isEmpty();
    int size();
};

#endif
