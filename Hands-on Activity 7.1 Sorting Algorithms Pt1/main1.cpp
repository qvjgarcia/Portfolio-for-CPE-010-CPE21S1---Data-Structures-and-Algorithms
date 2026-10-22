#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

void displayValues(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void copyArray(const int src[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

int main(){

    srand(time(0));

    int numbers[100];
    for (int i = 0; i < 100; i++) {
        numbers[i] = rand();
    }

    std::cout << "--- PREPARATION TASK: ORIGINAL UNSORTED ARRAY ---" << std::endl;
    displayValues(numbers, 100);

    int tempArr[100];

    std::cout << "\n--- A.1 BUBBLE SORT ---" << std::endl;
    copyArray(numbers, tempArr, 100);
    bubbleSort(tempArr, 100);
    displayValues(tempArr, 100);

    std::cout << "\n--- A.2 SELECTION SORT ---" << std::endl;
    copyArray(numbers, tempArr, 100);
    selectionSort(tempArr, 100);
    displayValues(tempArr, 100);

    std::cout << "\n--- A.3 INSERTION SORT ---" << std::endl;
    copyArray(numbers, tempArr, 100);
    insertionSort(tempArr, 100);
    displayValues(tempArr, 100);

    return 0;
}