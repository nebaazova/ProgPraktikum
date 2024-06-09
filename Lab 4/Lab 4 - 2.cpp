#include <iostream>
#include <vector>
#include <cmath>

// Функция для нахождения определителя матрицы 2x2
double determinant(std::vector<std::vector<double>> matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// Функция для решения системы методом Крамера
std::vector<double> solveUsingCramer(std::vector<std::vector<double>> A, std::vector<double> b) {
    int n = A.size();
    std::vector<double> x(n);

    // Находим определитель матрицы коэффициентов A
    double det_A = determinant(A);

    // Решаем для каждого неизвестного
    for (int i = 0; i < n; ++i) {
        // Создаем копию матрицы коэффициентов и заменяем i-й столбец на вектор правых частей b
        std::vector<std::vector<double>> A_copy = A;
        for (int j = 0; j < n; ++j) {
            A_copy[j][i] = b[j];
        }

        // Находим определитель этой матрицы
        double det_A_i = determinant(A_copy);

        // Вычисляем i-е неизвестное
        x[i] = det_A_i / det_A;
    }

    return x;
}

// Функция для решения системы методом Якоби
std::vector<double> solveUsingJacobi(std::vector<std::vector<double>> A, std::vector<double> b, double tolerance, int max_iterations) {
    int n = A.size();
    std::vector<double> x(n, 0.0);
    std::vector<double> x_new(n);
    int iter = 0;

    // Итерационный процесс
    while (iter < max_iterations) {
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        // Проверка на достижение необходимой точности
        bool converged = true;
        for (int i = 0; i < n; ++i) {
            if (std::abs(x_new[i] - x[i]) > tolerance) {
                converged = false;
                break;
            }
        }

        if (converged) {
            break;
        }

        x = x_new;
        iter++;
    }

    return x;
}

int main() {
    // Матрица коэффициентов
    std::vector<std::vector<double>> A = {{3, 12, -5}, {3, 5, -2}, {-1, 2, -1}};
    // Вектор правых частей
    std::vector<double> b = {1, 1, 1};

    // Решение методом Крамера
    std::vector<double> x_cramer = solveUsingCramer(A, b);
    std::cout << "Решение СЛАУ методом Крамера:" << std::endl;
    for (size_t i = 0; i < x_cramer.size(); ++i) {
        std::cout << "x_" << i+1 << " = " << x_cramer[i] << std::endl;
    }

    // Решение методом Якоби
    std::vector<double> x_jacobi = solveUsingJacobi(A, b, 1e-6, 1000);
    std::cout << "Решение СЛАУ методом Якоби:" << std::endl;
    for (size_t i = 0; i < x_jacobi.size(); ++i) {
        std::cout << "x_" << i+1 << " = " << x_jacobi[i] << std::endl;
    }

    return 0;
}
