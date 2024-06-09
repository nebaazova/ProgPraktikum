#include <iostream>
#include <cmath>

int main() {
    const double epsilon = 1e-6;
    double sum = 0.0;
    double term;
    int k = 1;
    double x = M_PI / 4;  // Можно заменить на любое значение x

    do {
        term = std::pow(-1, k) / (std::sin(k * x) + 6 + k * k);
        sum += term;
        k++;
    } while (std::fabs(term) > epsilon);

    std::cout << "Сумма функционального ряда с точностью до " << epsilon << " равна: " << sum << std::endl;

    return 0;
}
