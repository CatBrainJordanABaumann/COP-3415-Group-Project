#include <iostream>
#include "MinHeap.h"

int main() {
    std::cout << "Hello World" << std::endl;

    MinHeap<int> testHeap;
    std::cout << "Values: ";
    for (int i = 0; i < 50; i++) {
        int value = rand() % 100;
        std::cout << value << ' ';
        testHeap.push(value);
    }

    std::cout << std::endl << "Min Heap: ";
    testHeap.print();

    std::cout << "\nHeapified: ";
    while (!testHeap.empty())
        std::cout << testHeap.pop() << ' ';

    std::cout << std::endl;

    return 0;
}