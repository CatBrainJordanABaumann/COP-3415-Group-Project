#ifndef STACK_H
#define STACK_H

//stores data and pointer for next node in stack
template <typename T>
struct StackNode {
    T data;
    StackNode<T>* next;
};

template <typename T>
class Stack
{

private:
    StackNode<T>* topNode;
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

#endif
