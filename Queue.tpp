#pragma once

#include "Queue.h"

//Intitializes empty queue
template <typename T>
Queue<T>::Queue()
{
    front = nullptr;
    rear = nullptr;
    queueSize = 0;
}

//adds new item to end of a queue
template <typename T>
void Queue<T>::enqueue(T value)
{
    Node<T>* temp = new Node<T>(value);

    if(isEmpty())
    {
        front = rear = temp;
        queueSize++;
        return;
    }

    rear->next = temp;
    rear = temp;

    queueSize++;
}

//removes item from front of queue
template <typename T>
void Queue<T>::dequeue()
{
    if(isEmpty())
    {
        return;
    }

    Node<T>* temp = front;

    front = front->next;

    if(front == nullptr)
    {
        rear = nullptr;
    }

    delete temp;

    queueSize--;
}

//returns front item in the queue
template <typename T>
T Queue<T>::peek()
{
    return front->data;
}

//if empty queue
template <typename T>
bool Queue<T>::isEmpty()
{
    return front == nullptr;
}

//returns int size of queue
template <typename T>
int Queue<T>::size()
{
    return queueSize;
}