#ifndef QUEUE_H
#define QUEUE_H

//stores data and pointer to next node
template <typename T>
struct QueueNode
{
    T data;
    QueueNode<T>* next;
    //Node constructor
    QueueNode(T d)
    {
        data = d;
        next = nullptr;
    }
};

template <typename T>
class Queue
{
private:
    
    QueueNode<T>* front;
        
    QueueNode<T>* rear;
        
    int queueSize;

//queue fucntion declarations
public:
    Queue();

    void enqueue(T value);
    void dequeue();

    T peek();

    bool isEmpty();

    int size();
};

#endif
