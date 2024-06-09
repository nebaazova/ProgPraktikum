import math

# Функция, описывающая дифференциальное уравнение y' = -y * tan(x) + sin(2*x)
def f(x, y):
    return -y * math.tan(x) + math.sin(2 * x)

# Точное решение уравнения
def exact_solution(x):
    return -2 * math.cos(x) ** 2 + math.cos(x)

# Метод Эйлера-Коши для численного решения дифференциального уравнения
def euler_coshi_method(x0, y0, h, x_end):
    x_values = [x0]
    y_values = [y0]
    
    while x_values[-1] < x_end:
        x = x_values[-1]
        y = y_values[-1]
        
        # Первый шаг метода Эйлера
        y_euler = y + h * f(x, y)
        
        # Второй шаг метода Коши
        y_coshi = y + h * (f(x, y) + f(x + h, y_euler)) / 2
        
        # Добавляем новые значения в список
        x_values.append(x + h)
        y_values.append(y_coshi)
    
    return x_values, y_values

# Вычисление погрешности
def calculate_error(y_values, exact_values):
    error = [abs(y_values[i] - exact_values[i]) for i in range(len(exact_values))]
    return error

# Начальные условия
x0 = 0
y0 = -1

# Параметры расчета
x_end = 1
h = 0.1

# Точные значения для сравнения
exact_x_values = [x0 + i * h for i in range(int((x_end - x0) / h) + 1)]
exact_y_values = [exact_solution(x) for x in exact_x_values]

# Решение методом Эйлера-Коши
numerical_x_values, numerical_y_values = euler_coshi_method(x0, y0, h, x_end)

# Вычисление погрешности
error = calculate_error(numerical_y_values, exact_y_values)

# Вывод результатов
print("Точные значения:", exact_y_values)
print("Численные значения:", numerical_y_values)
print("Погрешность:", error)
