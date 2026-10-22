#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "sortingAlgo.h"

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 20 == 0) std::cout << "\n";
    }
    std::cout << "\n";
}

int main() {
    srand(time(0));
    const int SIZE = 100;

    std::string candidates[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    int votes[SIZE];
    int manualCounts[5] = {0};

    for (int i = 0; i < SIZE; i++) {
        votes[i] = (rand() % 5) + 1;
        manualCounts[votes[i] - 1]++;
    }

    std::cout << "--- UNSORTED VOTES ARRAY ---\n";
    printArray(votes, SIZE);

    insertionSort(votes, SIZE);

    std::cout << "--- SORTED VOTES ARRAY ---\n";
    printArray(votes, SIZE);

    int algorithmCounts[5] = {0};
    for (int i = 0; i < SIZE; i++) {
        algorithmCounts[votes[i] - 1]++;
    }

    std::cout << "--- COUNT RESULTS ---\n";
    int maxVotes = 0;
    int winnerIndex = 0;

    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << (i + 1) << " (" << candidates[i] << ")\n";
        std::cout << "  Manual Count    : " << manualCounts[i] << "\n";
        std::cout << "  Algorithm Count : " << algorithmCounts[i] << "\n\n";

        if (algorithmCounts[i] > maxVotes) {
            maxVotes = algorithmCounts[i];
            winnerIndex = i;
        }
    }

    std::cout << "WINNER: Candidate " << (winnerIndex + 1) << " (" << candidates[winnerIndex] << ")\n";
    
    return 0;
}