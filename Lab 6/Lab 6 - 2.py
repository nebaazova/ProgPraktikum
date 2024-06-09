import math

# Функция f(x1, x2)
def f(x1, x2):
    return x1 + 2 * x2 + 4 * math.sqrt(1 + x1 ** 2 + x2 ** 2)

# Градиент функции f(x1, x2)
def gradient_f(x1, x2):
    grad_x1 = (x1 / math.sqrt(1 + x1 ** 2 + x2 ** 2)) + 1
    grad_x2 = (x2 / math.sqrt(1 + x1 ** 2 + x2 ** 2)) + 2
    return grad_x1, grad_x2

# Метод наискорейшего спуска
def gradient_descent(learning_rate, max_iterations, epsilon):
    # Начальное значение x1 и x2
    x1 = 0.0
    x2 = 0.0
    
    # Выполнение итераций
    for i in range(max_iterations):
        grad_x1, grad_x2 = gradient_f(x1, x2)
        
        # Обновление значений x1 и x2
        x1 -= learning_rate * grad_x1
        x2 -= learning_rate * grad_x2
        
        # Проверка условия остановки
        if math.sqrt(grad_x1 ** 2 + grad_x2 ** 2) < epsilon:
            break
    
    return x1, x2

# Параметры метода наискорейшего спуска
learning_rate = 0.1
max_iterations = 1000
epsilon = 1e-6

# Вызов метода наискорейшего спуска
optimal_x1, optimal_x2 = gradient_descent(learning_rate, max_iterations, epsilon)

# Вывод результатов
print("Оптимум функции:")
print("x1 =", optimal_x1)
print("x2 =", optimal_x2)
print("Значение функции в оптимальной точке:", f(optimal_x1, optimal_x2))
