#include <Node.h>

template <typename T>
Node<T>::Node(T data, Node<T>* next) :
    data(data), next(next) { }