#ifndef DD7626E5_0FA1_43A8_BB81_B6C43003B603
#define DD7626E5_0FA1_43A8_BB81_B6C43003B603

class PI {
    public:
    // Konstruktor przyjmujący liczbę punktów i liczbę wątków
    PI(long long num_points, int num_threads);

    // Funkcja do obliczania całki
    double calculate();

    private:
    long long num_points;  // Liczba punktów (częstotliwość podziału przedziału całkowania)
    int num_threads; // Liczba wątków do równoległego obliczania

    // Funkcja obliczająca część całki w danym przedziale
    void calculate_integral(long long start, long long end, double& result);
};

#endif /* DD7626E5_0FA1_43A8_BB81_B6C43003B603 */
