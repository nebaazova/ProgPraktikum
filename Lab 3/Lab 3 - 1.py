import numpy as np

# Функция для интегрирования
def f(x):
    return x**4 / (6 + x**2)

# Метод прямоугольников (левый)
def rectangle_method(f, a, b, n):
    h = (b - a) / n
    result = 0.0
    for i in range(n):
        result += f(a + i * h)
    return result * h

# Метод трапеций
def trapezoidal_method(f, a, b, n):
    h = (b - a) / n
    result = (f(a) + f(b)) / 2.0
    for i in range(1, n):
        result += f(a + i * h)
    return result * h

# Метод Симпсона
def simpson_method(f, a, b, n):
    if n % 2 == 1:  # n должен быть четным для метода Симпсона
        n += 1
    h = (b - a) / n
    result = f(a) + f(b)
    for i in range(1, n, 2):
        result += 4 * f(a + i * h)
    for i in range(2, n-1, 2):
        result += 2 * f(a + i * h)
    return result * h / 3.0

# Параметры интегрирования
a, b = 1, 2
n = 1000  # Количество разбиений

# Вычисление интегралов
rectangle_result = rectangle_method(f, a, b, n)
trapezoidal_result = trapezoidal_method(f, a, b, n)
simpson_result = simpson_method(f, a, b, n)

# Вывод результатов
print(f"Интеграл методом прямоугольников: {rectangle_result}")
print(f"Интеграл методом трапеций: {trapezoidal_result}")
print(f"Интеграл методом Симпсона: {simpson_result}")
