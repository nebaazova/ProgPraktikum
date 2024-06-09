import numpy as np

def seidel(A, b, tol=1e-6, max_iterations=1000):
    n = len(b)
    x = np.zeros_like(b, dtype=np.double)
    
    for it in range(max_iterations):
        x_new = np.copy(x)
        
        for i in range(n):
            s1 = np.dot(A[i, :i], x_new[:i])
            s2 = np.dot(A[i, i + 1:], x[i + 1:])
            x_new[i] = (b[i] - s1 - s2) / A[i, i]
        
        if np.linalg.norm(x_new - x, ord=np.inf) < tol:
            return x_new
        
        x = x_new
    
    raise Exception(f"Решение не сошлось за {max_iterations} итераций")

# Матрица коэффициентов
A = np.array([
    [29, 8, 9, -9],
    [-7, -25, 0, 9],
    [1, 6, 16, -2],
    [-7, 4, -2, 17]
], dtype=float)

# Вектор правых частей
b = np.array([197, -226, -95, -58], dtype=float)

# Решение методом Зейделя
x_seidel = seidel(A, b)

print("Решение СЛАУ методом Зейделя:")
print(x_seidel)
