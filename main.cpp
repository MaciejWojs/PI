/**
 * @file main.cpp
 * @~english
 * @brief Main file for running the PI calculation and benchmarking.
 *
 * @~polish
 * @brief Główny plik do uruchamiania obliczeń PI i testów wydajnościowych.
 */

#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include "PI.hpp"

 /**
  * @~english
  * @brief Maximum number of threads that can be used.
  *
  * @~polish
  * @brief Maksymalna liczba wątków, które mogą być użyte.
  */
#define MAX_THREADS 50

  /**
   * @~english
   * @brief Filename for saving benchmark results.
   *
   * @~polish
   * @brief Nazwa pliku do zapisywania wyników testów wydajnościowych.
   */
#define FILENAME "benchmark.csv"

   /**
    * @~english
    * @brief Prompts the user to enter the number of threads to use.
    * @return The number of threads entered by the user.
    *
    * @~polish
    * @brief Prosi użytkownika o podanie liczby wątków do użycia.
    * @return Liczba wątków podana przez użytkownika.
    */
int get_num_threads();

/**
 * @~english
 * @brief Saves the benchmark results to a CSV file.
 * @param threads The number of threads used.
 * @param points The number of points used in the calculation.
 * @param result The result of the calculation.
 *
 * @~polish
 * @brief Zapisuje wyniki testów wydajnościowych do pliku CSV.
 * @param threads Liczba użytych wątków.
 * @param points Liczba punktów użytych w obliczeniach.
 * @param result Wynik obliczeń.
 */
void save_to_csv(int threads, long long points, double result);

/**
 * @~english
 * @brief Main function for running the PI calculation and benchmarking.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return Exit status of the program.
 *
 * @~polish
 * @brief Główna funkcja do uruchamiania obliczeń PI i testów wydajnościowych.
 * @param argc Liczba argumentów wiersza poleceń.
 * @param argv Tablica argumentów wiersza poleceń.
 * @return Status zakończenia programu.
 */
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