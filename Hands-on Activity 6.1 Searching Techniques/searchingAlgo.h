#include <iostream>
#include "node.h"
    
#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchArr(T data[], int arrSize, T datafind){

    int i=0;

    while(i < arrSize){
        if(datafind == data[i]){
        std::cout<<"the search is success"<<std::endl;
        return;
        }
        i++;
    }

    std::cout<<"the element is not found"<<std::endl;
    return;
    
}
template <typename T>
void linearSearchLL(Node<T>* node, T datafind){
    while(node != nullptr){
        if(datafind == node->data){
            std::cout<<"the search is success"<<std::endl;
            return;
        }
        node = node->next;
    }
    std::cout<<"the search was unsuccessful"<<std::endl;
    return;

}
template <typename T>
void linearsearchLL(Node<T>* node, T datafind){
    while(node != nullptr){
        if(node->data == datafind){
            std::cout<<"the search is success"<<std::endl;
            return;
        }
        node = node->next;
    }
    std::cout<<"the search was unsuccessful"<<std::endl;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;
    while(fast != last && fast->next != last){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
template <typename T>
void binarySearchLL(Node<T>* head, T datafind){
    Node<T>* start = head;
    Node<T>* end = nullptr;

    while(start != end){
        Node<T>* mid = getMiddle<T>(start, end);
        if(mid == nullptr) break;
        if(mid->data == datafind){
            std::cout<<"the search is success"<<std::endl;
            return;
        }
        if(mid->data < datafind){
            start = mid->next;
        } else {
            end = mid;
        }
    }

    std::cout<<"the element is not found"<<std::endl;
    return;

}
//create a binary search using array : getMiddle and / binarySearchArr


#endif 
