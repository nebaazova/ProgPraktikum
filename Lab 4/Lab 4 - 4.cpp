#include <iostream>
#include <vector>

// Функция для решения СЛАУ методом прогонки
std::vector<double> solveByTridiagonalMatrixAlgorithm(const std::vector<double>& lowerDiagonal, 
                                                      std::vector<double> mainDiagonal,
                                                      std::vector<double> upperDiagonal,
                                                      std::vector<double> rightHandSide) {
    int n = rightHandSide.size();
    std::vector<double> solution(n);
    
    // Прямой ход (forward elimination)
    for (int i = 1; i < n; ++i) {
        double factor = lowerDiagonal[i] / mainDiagonal[i-1];
        mainDiagonal[i] -= factor * upperDiagonal[i-1];
        rightHandSide[i] -= factor * rightHandSide[i-1];
    }
    
    // Обратный ход (backward substitution)
    solution[n-1] = rightHandSide[n-1] / mainDiagonal[n-1];
    for (int i = n-2; i >= 0; --i) {
        solution[i] = (rightHandSide[i] - upperDiagonal[i] * solution[i+1]) / mainDiagonal[i];
    }
    
    return solution;
}

int main() {
    // Матрица коэффициентов
    std::vector<double> lowerDiagonal = {0, 2, 4, -3, 0}; // Нижняя диагональ
    std::vector<double> mainDiagonal = {15, -15, 11, -3, 3}; // Главная диагональ
    std::vector<double> upperDiagonal = {8, 4, 5, 16, 8}; // Верхняя диагональ
    
    // Вектор правых частей
    std::vector<double> rightHandSide = {92, -84, -77, 15, -11};
    
    // Решение методом прогонки
    std::vector<double> solution = solveByTridiagonalMatrixAlgorithm(lowerDiagonal, mainDiagonal, upperDiagonal, rightHandSide);
    
    // Вывод решения
    std::cout << "Решение СЛАУ методом прогонки:" << std::endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        std::cout << "x_" << i+1 << " = " << solution[i] << std::endl;
    }
    
    return 0;
}
