import numpy as np

def gauss_elimination(A, b):
    n = len(b)
    # Прямой ход
    for i in range(n):
        # Поиск максимального элемента в текущем столбце
        max_row = i + np.argmax(np.abs(A[i:, i]))
        # Поменять местами текущую строку и строку с максимальным элементом
        A[[i, max_row]] = A[[max_row, i]]
        b[[i, max_row]] = b[[max_row, i]]
        
        # Нормализация текущей строки
        for k in range(i + 1, n):
            factor = A[k, i] / A[i, i]
            A[k, i:] -= factor * A[i, i:]
            b[k] -= factor * b[i]
    
    # Обратный ход
    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i + 1:], x[i + 1:])) / A[i, i]
    
    return x

# Матрица коэффициентов
A = np.array([
    [1, -5, -7, 1],
    [1, -3, -9, -4],
    [-2, 4, 2, 1],
    [-9, 9, 5, 3]
], dtype=float)  # Преобразование к типу float

# Вектор правых частей
b = np.array([-75, -41, 18, 29], dtype=float)  # Преобразование к типу float

# Решение методом Гаусса
A_gauss = A.copy()
b_gauss = b.copy()
x_gauss = gauss_elimination(A_gauss, b_gauss)

print("Решение СЛАУ методом Гаусса:")
print(x_gauss)

# Решение методом обратной матрицы
A_inv = np.linalg.inv(A)
x_inv = np.dot(A_inv, b)

print("Решение СЛАУ методом обратной матрицы:")
print(x_inv)
