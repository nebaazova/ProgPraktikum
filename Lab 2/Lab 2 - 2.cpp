#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Структура для представления вектора в пространстве
struct Vector {
    double x, y, z;
};

// Функция для нахождения длины вектора
double vectorLength(const Vector& v) {
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Функция для нахождения угла между двумя векторами
double angleBetweenVectors(const Vector& v1, const Vector& v2) {
    double dotProduct = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    double length1 = vectorLength(v1);
    double length2 = vectorLength(v2);
    return std::acos(dotProduct / (length1 * length2));
}

// Функция для нахождения суммы двух векторов
Vector vectorSum(const Vector& v1, const Vector& v2) {
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

// Функция для нахождения разности двух векторов
Vector vectorDifference(const Vector& v1, const Vector& v2) {
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

// Функция для проверки параллельности векторов
bool areParallel(const Vector& v1, const Vector& v2) {
    Vector crossProd = {
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    };
    return crossProd.x == 0 && crossProd.y == 0 && crossProd.z == 0;
}

// Функция для нахождения векторного произведения двух векторов
Vector vectorCrossProduct(const Vector& v1, const Vector& v2) {
    return {
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    };
}

int main() {
    std::srand(std::time(0));

    // Случайные координаты векторов
    Vector v1 = {std::rand() % 20 - 10, std::rand() % 20 - 10, std::rand() % 20 - 10};
    Vector v2 = {std::rand() % 20 - 10, std::rand() % 20 - 10, std::rand() % 20 - 10};

    double length1 = vectorLength(v1);
    double length2 = vectorLength(v2);
    double angle = angleBetweenVectors(v1, v2) * 180.0 / M_PI;
    Vector sum = vectorSum(v1, v2);
    Vector diff = vectorDifference(v1, v2);
    bool parallel = areParallel(v1, v2);
    Vector crossProd = vectorCrossProduct(v1, v2);

    std::cout << "Длина первого вектора: " << length1 << std::endl;
    std::cout << "Длина второго вектора: " << length2 << std::endl;
    std::cout << "Угол между векторами: " << angle << " градусов" << std::endl;
    std::cout << "Сумма векторов: (" << sum.x << ", " << sum.y << ", " << sum.z << ")" << std::endl;
    std::cout << "Разность векторов: (" << diff.x << ", " << diff.y << ", " << diff.z << ")" << std::endl;
    std::cout << "Векторы " << (parallel ? "параллельны" : "не параллельны") << std::endl;
    std::cout << "Векторное произведение: (" << crossProd.x << ", " << crossProd.y << ", " << crossProd.z << ")" << std::endl;

    return 0;
}
