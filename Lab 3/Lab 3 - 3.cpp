#include <iostream>
#include <cmath>

int main() {
    const double epsilon = 1e-6;
    double sum = 0.0;
    double term;
    int k = 1;

    do {
        term = 6.0 / std::pow(2, k-1) + std::pow(-1, k-1) / (2 * std::pow(3, k-1));
        sum += term;
        k++;
    } while (std::fabs(term) > epsilon);

    std::cout << "Сумма числового ряда с точностью до " << epsilon << " равна: " << sum << std::endl;

    return 0;
}
