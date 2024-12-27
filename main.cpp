#include <iostream>
#include <limits>
#include "PI.hpp"
#define MAX_THREADS 50

int get_num_threads();

int main(int argc, char** argv) {
    int num_threads = get_num_threads();

    int num_points = 1000000000;
    PI pi(num_points, num_threads);
    std::cout << pi.calculate() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int get_num_threads() {
    std::cout << "How many threads do you want to use?\n>>> ";
    int num_threads;
    while (true) {
        std::cin >> num_threads;
        if (std::cin.fail() || num_threads < 1 || num_threads > MAX_THREADS) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number between 1 and " << MAX_THREADS << std::endl;
            std::cout << ">>> ";
        } else {
            break;
        }
    }
    return num_threads;
}