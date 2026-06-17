#include "Stack.h"

    template <typename T>
    Stack<T>::Stack()
    {
        topNode = nullptr;
        stackSize = 0;
    }
    
    template <typename T>
    void Stack<T>::push(T value)
    {
        Node<T>* temp = new Node<T>;

        temp->data = value;
        temp->next = topNode;

        topNode = temp;
        stackSize++;
    }
    
    template <typename T>
    void Stack<T>::pop()
    {
    if(isEmpty())
    {
        return;
    }

    Node<T>* temp = topNode;

    topNode = topNode->next;

    delete temp;

    stackSize--;  
    }
    
    template <typename T>
    T Stack<T>::peek()
    {
        return topNode->data;
    }
    
    template <typename T>
    bool Stack<T>::isEmpty()
    {
     return topNode == nullptr;
    }
    
    template <typename T>
    int Stack<T>::size()
    {
        return stackSize;
    }