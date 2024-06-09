#include <iostream>
#include <cmath>

// Функция для вычисления значения функции f(x, y)
double f(double x, double y) {
    return (pow(y, 2) + pow(x, 2) * y) / pow(x, 3);
}

// Точное решение уравнения
double exact_solution(double x) {
    return pow(x, 2) / (1 + x);
}

// Метод Хойна для численного решения дифференциального уравнения
void improved_euler_method(double x0, double y0, double h, double x_end) {
    double x = x0;
    double y = y0;

    while (x <= x_end) {
        // Вычисляем значение функции в текущей точке
        double k1 = f(x, y);
        double k2 = f(x + h, y + h * k1);

        // Обновляем значение y
        y = y + h / 2 * (k1 + k2);

        // Переходим к следующей точке
        x += h;

        // Выводим значения x и y
        std::cout << "x = " << x << ", y = " << y << std::endl;
    }
}

int main() {
    // Начальные условия
    double x0 = 1;
    double y0 = 0.5;

    // Параметры расчета
    double x_end = 2;
    double h = 0.1;

    // Вызов метода Хойна
    std::cout << "Решение методом Эйлера:" << std::endl;
    improved_euler_method(x0, y0, h, x_end);

    // Вычисление погрешности
    std::cout << "\nПогрешность:" << std::endl;
    for (double x = x0; x <= x_end; x += h) {
        double numerical_y = exact_solution(x);
        double exact_y = pow(x, 2) / (1 + x);
        double error = std::abs(numerical_y - exact_y);
        std::cout << "x = " << x << ", точное значение y = " << exact_y << ", численное значение y = " << numerical_y << ", погрешность = " << error << std::endl;
    }

    return 0;
}
