#include "Stack.h"
    //intitializes a empty stack
    template <typename T>
    Stack<T>::Stack()
    {
        topNode = nullptr;
        stackSize = 0;
    }
    
    //adds item to top of stack
    template <typename T>
    void Stack<T>::push(T value)
    {
        StackNode<T>* temp = new StackNode<T>;

        temp->data = value;
        temp->next = topNode;

        topNode = temp;
        stackSize++;
    }
    
    //removes item from top of stack
    template <typename T>
    void Stack<T>::pop()
    {
    if(isEmpty())
    {
        return;
    }

    StackNode<T>* temp = topNode;

    topNode = topNode->next;

    delete temp;

    stackSize--;  
    }
    
    //returns item in the top node
    template <typename T>
    T Stack<T>::peek()
    {
        return topNode->data;
    }
    
    //checks if stack is empty
    template <typename T>
    bool Stack<T>::isEmpty()
    {
     return topNode == nullptr;
    }
    
    //returns the number of items in the stack
    template <typename T>
    int Stack<T>::size()
    {
        return stackSize;
    }