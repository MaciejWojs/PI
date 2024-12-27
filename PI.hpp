/**
 * @file PI.hpp
 * @~english
 * @brief Header file for the PI class, which calculates the integral of PI using multiple threads.
 *
 * @~polish
 * @brief Plik nagłówkowy dla klasy PI, która oblicza całkę PI przy użyciu wielu wątków.
 */

#ifndef DD7626E5_0FA1_43A8_BB81_B6C43003B603
#define DD7626E5_0FA1_43A8_BB81_B6C43003B603

 /**
  * @~english
  * @brief Class for calculating the integral of PI using multiple threads.
  *
  * @~polish
  * @brief Klasa do obliczania całki PI przy użyciu wielu wątków.
  */
class PI {
    public:
    /**
     * @~english
     * @brief Deleted default constructor to prevent instantiation without parameters.
     *
     * @~polish
     * @brief Usunięty domyślny konstruktor, aby zapobiec tworzeniu instancji bez parametrów.
     */
    PI() = delete;

    /**
     * @~english
     * @brief Constructor that initializes the number of points and threads.
     * @param num_points Number of points (frequency of interval division for integration).
     * @param num_threads Number of threads for parallel computation.
     *
     * @~polish
     * @brief Konstruktor inicjalizujący liczbę punktów i wątków.
     * @param num_points Liczba punktów (częstotliwość podziału przedziału całkowania).
     * @param num_threads Liczba wątków do równoległego obliczania.
     */
    PI(long long num_points, int num_threads);

    /**
     * @~english
     * @brief Function to calculate the integral and measure execution time.
     * @return Time taken to calculate the integral in seconds.
     *
     * @~polish
     * @brief Funkcja do obliczania całki i pomiaru czasu wykonania.
     * @return Czas wykonania obliczenia całki w sekundach.
     */
    double calculate();

    private:
    long long num_points; ///< @~english Number of points (frequency of interval division for integration) @~polish Liczba punktów (częstotliwość podziału przedziału całkowania)
    int num_threads; ///< @~english Number of threads for parallel computation @~polish Liczba wątków do równoległego obliczania

    /**
     * @~english
     * @brief Function to calculate a part of the integral in a given range.
     * @param start Start of the range.
     * @param end End of the range.
     * @param result Reference to store the result of the calculation.
     *
     * @~polish
     * @brief Funkcja obliczająca część całki w danym przedziale.
     * @param start Początek przedziału.
     * @param end Koniec przedziału.
     * @param result Referencja do przechowywania wyniku obliczeń.
     */
    void calculate_integral(long long start, long long end, double& result);
};

#endif /* DD7626E5_0FA1_43A8_BB81_B6C43003B603 */
