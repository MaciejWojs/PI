#include "PI.hpp"

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
