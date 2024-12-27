#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include "PI.hpp"
#define MAX_THREADS 50
#define FILENAME "benchmark.csv"

int get_num_threads();
void save_to_csv(int threads, long long points, double result);

int main(int argc, char** argv) {
    if (argc > 1 && std::string(argv[1]) == "--benchmark") {
        long long num_points[3] = { 100000000, 1000000000, 3000000000 };
        for (auto num_point : num_points) {
            std::cout << "Points: " << num_point << std::endl;
            for (int i = 1; i <= MAX_THREADS; i++) {
                PI pi(num_point, i);
                double result = pi.calculate();
                std::cout << "Threads: " << i << " Points: " << num_point << " Time: " << result << std::endl;
                save_to_csv(i, num_point, result);
            }
        }
    } else {
        int num_threads = get_num_threads();
        int num_points = 1000000000;

        PI pi(num_points, num_threads);
        std::cout << pi.calculate() << std::endl;
        std::cout << "Hello, World!" << std::endl;
        return 0;
    }
}

void save_to_csv(int threads, long long points, double result) {
    std::ofstream file(FILENAME, std::ios::app);
    file << threads << "," << points << "," << result << std::endl;
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