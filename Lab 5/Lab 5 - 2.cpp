#include <iostream>
#include <vector>
#include <cmath>

// Функция для вычисления значения интерполяционного многочлена Лагранжа в точке x
double lagrange_interpolation(double x, const std::vector<double>& x_values, const std::vector<double>& y_values) {
    double result = 0.0;
    for (size_t i = 0; i < x_values.size(); ++i) {
        double term = y_values[i];
        for (size_t j = 0; j < x_values.size(); ++j) {
            if (j != i) {
                term *= (x - x_values[j]) / (x_values[i] - x_values[j]);
            }
        }
        result += term;
    }
    return result;
}

// Функция для вычисления погрешности интерполяции в точке x
double interpolation_error(double x, double interpolated_value) {
    // Истинное значение функции в точке x
    double true_value = sin(x);
    // Погрешность
    double error = std::abs(true_value - interpolated_value);
    return error;
}

int main() {
    // Значения узлов интерполяции и функции в них
    std::vector<double> x_values = {0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI};
    std::vector<double> y_values;
    for (auto x : x_values) {
        y_values.push_back(sin(x));
    }

    // Вычисление значения интерполяционного многочлена Лагранжа в точке x = 0.25*pi
    double x = 0.25 * M_PI;
    double interpolated_value = lagrange_interpolation(x, x_values, y_values);
    std::cout << "Значение интерполяционного многочлена Лагранжа в точке x = 0.25*pi: " << interpolated_value << std::endl;

    // Вычисление погрешности интерполяции в точке x = 0.25*pi
    double error = interpolation_error(x, interpolated_value);
    std::cout << "Погрешность интерполяции в точке x = 0.25*pi: " << error << std::endl;

    return 0;
}
