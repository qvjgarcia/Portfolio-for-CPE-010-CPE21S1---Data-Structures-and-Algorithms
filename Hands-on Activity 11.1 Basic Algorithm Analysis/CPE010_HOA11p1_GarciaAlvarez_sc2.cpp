#include <iostream>
#include <chrono>

bool is_unique(int* A, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}

void uniqueness_test(int size) {
    int* A = new int[size];

    for (int i = 0; i < size; i++) {
        A[i] = i;
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    bool result = is_unique(A, size);
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time taken to search = " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
              << " microseconds" << std::endl;

    delete[] A;
}

int main() {
    uniqueness_test(1000);
    uniqueness_test(5000);
    uniqueness_test(10000);

    return 0;
}