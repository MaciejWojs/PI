#include "PI.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

/**
 * @file PI.cpp
 * @~english
 * @brief Implementation of the PI class for calculating the approximate value of PI using the numerical integration method.
 *
 * @~polish
 * @brief Implementacja klasy PI do obliczania przybliżonej wartości liczby PI za pomocą metody całkowania numerycznego.
 */

PI::PI(long long num_points, int num_threads)
    : num_points(num_points), num_threads(num_threads) {
}

void PI::calculate_integral(long long start, long long end, double& result) {
    double step = 1.0 / num_points;
    double local_sum = 0.0;

    // Suma w obrębie przedziału (start, end)
    for (long long i = start; i < end; i++) {
        double x = (i + 0.5) * step;  // Punkt środkowy prostokąta
        local_sum += 4.0 / (1.0 + x * x);  // Funkcja 4 / (1 + x^2) dla obliczenia PI
    }

    result = local_sum * step;  // Przemnożenie przez szerokość prostokątów
}

double PI::calculate() {
    double result = 0.0;
    long long points_per_thread = num_points / num_threads;

    // Wektor do przechowywania wyników wątków
    std::vector<std::thread> threads;
    std::vector<double> results(num_threads, 0.0);

    // Zaczynamy mierzyć czas
    auto start_time = std::chrono::high_resolution_clock::now();

    // Tworzymy wątki
    for (int i = 0; i < num_threads; ++i) {
        long long start = i * points_per_thread;
        long long end = (i == num_threads - 1) ? num_points : (i + 1) * points_per_thread;
        threads.push_back(std::thread(&PI::calculate_integral, this, start, end, std::ref(results[i])));
    }

    // Czekamy na zakończenie wszystkich wątków
    for (auto& t : threads) {
        t.join();
    }

    // Sumujemy wyniki z każdego wątku
    for (int i = 0; i < num_threads; ++i) {
        result += results[i];
    }

    // Zatrzymujemy mierzenie czasu
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;

    // Display the result
    std::cout << "Approximate value of PI with " << num_points << " samples and " << threads.size() << " threads: " << result << std::endl;
    std::cout << "Calculation time: " << duration.count() << " seconds" << std::endl;

    return duration.count();
}