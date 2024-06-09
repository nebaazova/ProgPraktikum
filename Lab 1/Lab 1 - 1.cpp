#include <iostream>
#include <cmath>

struct Complex {
    double real;
    double imag;

    // Конструктор по умолчанию
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Сложение комплексных чисел
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Вычитание комплексных чисел
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Умножение комплексных чисел
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Деление комплексных чисел
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator, 
                       (imag * other.real - real * other.imag) / denominator);
    }

    // Возведение в степень
    Complex power(int n) const {
        Complex result = *this;
        for (int i = 1; i < n; ++i) {
            result = result * (*this);
        }
        return result;
    }

    // Корень n-ой степени
    Complex root(int n) const {
        double r = std::sqrt(real * real + imag * imag);
        double theta = std::atan2(imag, real);
        double root_r = std::pow(r, 1.0 / n);
        double root_theta = theta / n;
        return Complex(root_r * std::cos(root_theta), root_r * std::sin(root_theta));
    }

    // Печать комплексного числа
    void print() const {
        std::cout << real << (imag >= 0 ? " + " : " - ") << std::abs(imag) << "i" << std::endl;
    }
};

int main() {
    Complex z1(1, 1); // 1 + i
    Complex z2(5, -3); // 5 - 3i

    // Сложение
    Complex sum = z1 + z2;
    std::cout << "Сумма: ";
    sum.print();

    // Разность
    Complex diff = z1 - z2;
    std::cout << "Разность: ";
    diff.print();

    // Произведение
    Complex prod = z1 * z2;
    std::cout << "Произведение: ";
    prod.print();

    // Частное
    Complex quot = z1 / z2;
    std::cout << "Частное: ";
    quot.print();

    // 4-я степень числа 2 - i
    Complex z3(2, -1);
    Complex pow_result = z3.power(4);
    std::cout << "4-я степень числа 2 - i: ";
    pow_result.print();

    // Корень 3-й степени числа 2 - i
    Complex root_result = z3.root(3);
    std::cout << "Корень 3-й степени числа 2 - i: ";
    root_result.print();

    return 0;
}
