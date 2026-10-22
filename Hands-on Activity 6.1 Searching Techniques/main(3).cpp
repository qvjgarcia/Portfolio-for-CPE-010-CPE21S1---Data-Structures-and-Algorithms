#include <iostream>
#include <cstdlib>
#include <time.h>
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main(){

    int dataset[max_size];
    srand(time(0)); // Seed the random number generator with the current time
    for(int i = 0; i < max_size; i++){
        dataset[i] = rand();
    }
    for(int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    int toFind;
    std::cout<<"what value you want to search: ";
    std::cin>>toFind;


    linearSearchArr(dataset, max_size, toFind);
    
    Node<char>* name1 = createNode('J');
    Node<char>* name2 = createNode('I');
    Node<char>* name3 = createNode('M');
    Node<char>* name4 = createNode('L');
    Node<char>* name5 = createNode('O');
    Node<char>* name6 = createNode('R');
    Node<char>* name7 = createNode('D');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;
    name7->next = nullptr;

    std::cout<<"Linear search for linked list result: ";
    linearSearchLL(name1, 'D');
    std::cout<<"Linear search for linked list result: ";
    linearSearchLL(name1, 'x');

    std::cout<<"Binary search for linked list result: ";
    binarySearchLL<char>(name1, 'M');
    std::cout<<"Binary search for linked list result: ";
    binarySearchLL<char>(name1, 'x');


    return 0;
}
