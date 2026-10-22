#include <iostream>
#include <iomanip>
#include <chrono>

// Linear recursion: x^n = x * x^(n-1)
unsigned long long rpower(unsigned long long x, int n, long long &counter) {
    if (n == 0) return 1;
    counter++;
    return x * rpower(x, n - 1, counter);
}

// Binary (divide-and-conquer) recursion
unsigned long long brpower(unsigned long long x, int n, long long &counter) {
    if (n == 0) return 1;
    if (n % 2 == 1) {
        unsigned long long y = brpower(x, (n - 1) / 2, counter);
        counter += 2;
        return x * y * y;
    } else {
        unsigned long long y = brpower(x, n / 2, counter);
        counter += 1;
        return y * y;
    }
}

int main() {
    int sizes[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1000};
    const int REPEATS = 10000;            // repeat runs so the timing is measurable
    volatile unsigned long long sink = 0; // keeps the compiler from removing the calls

    std::cout << std::left << std::setw(8) << "n"
              << std::setw(14) << "rpower_mult"
              << std::setw(14) << "brpower_mult"
              << std::setw(16) << "rpower_time(us)"
              << std::setw(16) << "brpower_time(us)" << "\n";

    for (int n : sizes) {
        long long c1 = 0, c2 = 0;
        rpower(2, n, c1);
        brpower(2, n, c2);

        auto t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < REPEATS; i++) {
            long long tmp = 0;
            sink = rpower(2, n, tmp);
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < REPEATS; i++) {
            long long tmp = 0;
            sink = brpower(2, n, tmp);
        }
        auto t3 = std::chrono::high_resolution_clock::now();

        double rTime = std::chrono::duration<double, std::micro>(t2 - t1).count() / REPEATS;
        double bTime = std::chrono::duration<double, std::micro>(t3 - t2).count() / REPEATS;

        std::cout << std::left << std::setw(8) << n
                  << std::setw(14) << c1
                  << std::setw(14) << c2
                  << std::setw(16) << std::fixed << std::setprecision(4) << rTime
                  << std::setw(16) << bTime << "\n";
    }
    return 0;
}