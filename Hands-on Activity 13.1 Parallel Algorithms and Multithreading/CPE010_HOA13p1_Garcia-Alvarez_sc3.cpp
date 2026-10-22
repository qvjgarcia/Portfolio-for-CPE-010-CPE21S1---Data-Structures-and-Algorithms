#include <iostream>
#include <thread>

int counter = 0;

void add(int value) {
    counter += value;
}

int main() {
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    std::cout << "Value before T1.join(): " << counter << std::endl;
    T1.join();

    std::cout << "Value before T2.join(): " << counter << std::endl;
    T2.join();

    std::cout << "Value before T3.join(): " << counter << std::endl;
    T3.join();

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}