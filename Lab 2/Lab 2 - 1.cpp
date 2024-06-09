#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Структура для представления точки
struct Point {
    double x, y;
};

// Структура для представления прямой в формате Ax + By + C = 0
struct Line {
    double A, B, C;
};

// Функция для нахождения расстояния от точки до прямой
double distanceFromPointToLine(const Point& p, const Line& l) {
    return std::abs(l.A * p.x + l.B * p.y + l.C) / std::sqrt(l.A * l.A + l.B * l.B);
}

// Функция для нахождения точки пересечения двух прямых
Point intersectionPoint(const Line& l1, const Line& l2) {
    double determinant = l1.A * l2.B - l2.A * l1.B;
    if (determinant == 0) {
        throw std::runtime_error("Прямые параллельны и не пересекаются.");
    }
    double x = (l2.B * l1.C - l1.B * l2.C) / determinant;
    double y = (l1.A * l2.C - l2.A * l1.C) / determinant;
    return {x, y};
}

// Функция для нахождения угла между двумя прямыми
double angleBetweenLines(const Line& l1, const Line& l2) {
    double dotProduct = l1.A * l2.A + l1.B * l2.B;
    double magnitude1 = std::sqrt(l1.A * l1.A + l1.B * l1.B);
    double magnitude2 = std::sqrt(l2.A * l2.A + l2.B * l2.B);
    return std::acos(dotProduct / (magnitude1 * magnitude2));
}

int main() {
    std::srand(std::time(0));

    // Случайные параметры прямых
    Line l1 = {std::rand() % 10 + 1, std::rand() % 10 + 1, std::rand() % 20 - 10};
    Line l2 = {std::rand() % 10 + 1, std::rand() % 10 + 1, std::rand() % 20 - 10};

    // Случайная точка
    Point p = {std::rand() % 20 - 10, std::rand() % 20 - 10};

    try {
        double dist1 = distanceFromPointToLine(p, l1);
        double dist2 = distanceFromPointToLine(p, l2);
        Point intersection = intersectionPoint(l1, l2);
        double distToIntersection = std::sqrt((p.x - intersection.x) * (p.x - intersection.x) + 
                                              (p.y - intersection.y) * (p.y - intersection.y));
        double angle = angleBetweenLines(l1, l2) * 180.0 / M_PI;

        std::cout << "Расстояние от точки до первой прямой: " << dist1 << std::endl;
        std::cout << "Расстояние от точки до второй прямой: " << dist2 << std::endl;
        std::cout << "Точка пересечения прямых: (" << intersection.x << ", " << intersection.y << ")" << std::endl;
        std::cout << "Расстояние от точки до точки пересечения: " << distToIntersection << std::endl;
        std::cout << "Угол между прямыми: " << angle << " градусов" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
