#include <iostream>
#include "PI.hpp"

int main(int argc, char** argv) {
    std::cout << "Enter the number of threads: ";
    int num_threads;
    std::cin >> num_threads;

    int num_points = 1000000000;
    PI pi(num_points, num_threads);
    std::cout << pi.calculate() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}