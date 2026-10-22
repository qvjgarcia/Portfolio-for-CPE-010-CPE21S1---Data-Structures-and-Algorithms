#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#include <iostream>

template <typename T>
class doubleList {
public:
    T data;
    doubleList<T>* next = nullptr;
    doubleList<T>* prev = nullptr;

    doubleList(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
doubleList<T>* newNode(T data) {
    return new doubleList<T>(data);
}

template <typename T>
void dllTraverse(doubleList<T>* currentNode) {
    doubleList<T>* tail = nullptr;

    std::cout << "Forward traversal \n";
    while (currentNode != nullptr) {
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    std::cout << std::endl;

    std::cout << "Reverse traversal \n";
    while (tail != nullptr) {
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
    std::cout << std::endl;
}

#endif