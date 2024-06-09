import math

def f(x):
    return 2 / (1 + x) - 3 * math.sin(x)

def bisection_method(a, b, tol=1e-6):
    if f(a) * f(b) > 0:
        raise ValueError("f(a) и f(b) должны иметь разные знаки")

    while (b - a) / 2 > tol:
        c = (a + b) / 2
        if f(c) == 0:
            return c
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c
    return (a + b) / 2

def g(x):
    return 2 / (1 + x) / 3

def iteration_method(x0, tol=1e-6, max_iter=1000):
    x = x0
    for _ in range(max_iter):
        x_new = g(x)
        if abs(x_new - x) < tol:
            return x_new
        x = x_new
    raise ValueError("Метод не сошелся")

def secant_method(x0, x1, tol=1e-6, max_iter=1000):
    for _ in range(max_iter):
        if f(x0) == f(x1):
            raise ValueError("f(x0) и f(x1) не должны быть равны")

        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        if abs(x2 - x1) < tol:
            return x2
        x0, x1 = x1, x2
    raise ValueError("Метод не сошелся")

def df(x):
    return -2 / (1 + x)**2 - 3 * math.cos(x)

def newton_method(x0, tol=1e-6, max_iter=1000):
    x = x0
    for _ in range(max_iter):
        x_new = x - f(x) / df(x)
        if abs(x_new - x) < tol:
            return x_new
        x = x_new
    raise ValueError("Метод не сошелся")
    
a, b = 0, 1  # Интервал для метода дихотомии
x0 = 0.5    # Начальное приближение для методов простых итераций, хорд и Ньютона

# Метод дихотомии
root_bisection = bisection_method(a, b)
print(f"Корень (метод дихотомии): {root_bisection}")

# Метод простых итераций
root_iteration = iteration_method(x0)
print(f"Корень (метод итераций): {root_iteration}")

# Метод хорд
root_secant = secant_method(a, b)
print(f"Корень (метод хорд): {root_secant}")

# Метод Ньютона
root_newton = newton_method(x0)
print(f"Корень (метод Ньютона): {root_newton}")

