#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>
class Stack
{

private:
    Node<T>* topNode;
    int stackSize;
public:
    //stack functions
    Stack();
    void push(T value);
    void pop();
    T peek();
    bool isEmpty();
    int size();
};
#include "Stack.tpp"
#endif
