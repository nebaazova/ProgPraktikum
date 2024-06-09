#include <iostream>
#include <cmath>

// Функция для вычисления значения функции f(x1, x2)
double f(double x1, double x2) {
    return x1 + 5 * pow(x2, 2) + exp(x1 + x2);
}

// Функция для нахождения оптимального значения x1 при фиксированном x2
double argmin_x1(double x2) {
    // Вычисляем производную функции по x1 и приравниваем к нулю
    // f'(x1) = 1 + e^(x1 + x2) = 0
    // => x1 = -x2 - ln(1)
    return -x2 - log(1.0);
}

// Функция для нахождения оптимального значения x2 при фиксированном x1
double argmin_x2(double x1) {
    // Вычисляем производную функции по x2 и приравниваем к нулю
    // f'(x2) = 10x2 + e^(x1 + x2) = 0
    // => x2 = -e^(x1) / 10
    return -exp(x1) / 10.0;
}

int main() {
    double x1 = 0.0; // Начальное значение x1
    double x2 = 0.0; // Начальное значение x2
    double epsilon = 1e-6; // Точность
    int max_iterations = 1000; // Максимальное количество итераций

    for (int i = 0; i < max_iterations; ++i) {
        // Сохраняем текущие значения x1 и x2
        double prev_x1 = x1;
        double prev_x2 = x2;
        
        // Вычисляем оптимальные значения x1 и x2
        x1 = argmin_x1(prev_x2);
        x2 = argmin_x2(prev_x1);
        
        // Проверяем условие остановки
        if (std::abs(prev_x1 - x1) < epsilon && std::abs(prev_x2 - x2) < epsilon) {
            break;
        }
    }

    // Выводим найденный оптимум
    std::cout << "Оптимум функции: f(" << x1 << ", " << x2 << ") = " << f(x1, x2) << std::endl;

    return 0;
}
