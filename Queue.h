#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue
{
private:
    
    Node<T>* front;
        
    Node<T>* rear;
        
    int queueSize;

//queue fucntion declarations
public:
    Queue();
    ~Queue();

    void enqueue(T value);
    void dequeue();

    T peek();

    bool isEmpty();

    int size();
};
#include "Queue.tpp"
#endif
