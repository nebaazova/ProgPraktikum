# Узлы интерполяции
x = [0.0, 1.0, 2.0, 3.0, 4.0]
y = [0.0, 0.5, 0.86603, 1.0, 0.86603]

# Разделение интервала на подотрезки
def split_intervals(x):
    intervals = []
    for i in range(len(x) - 1):
        intervals.append((x[i], x[i+1]))
    return intervals

# Нахождение коэффициентов сплайна для каждого подотрезка
def calculate_spline_coefficients(x, y):
    intervals = split_intervals(x)
    coefficients = []
    for i in range(len(intervals)):
        xi, xi1 = intervals[i]
        yi, yi1 = y[i], y[i+1]
        hi = xi1 - xi
        ai = yi
        bi = 0
        ci = 3 * (yi1 - yi) / hi**2
        di = 0
        coefficients.append((ai, bi, ci, di))
    return coefficients

# Вычисление значения сплайна в точке x
def spline_value(x, x_val, coefficients):
    for i in range(len(x) - 1):
        xi, xi1 = x[i], x[i+1]
        if xi <= x_val <= xi1:
            ai, bi, ci, di = coefficients[i]
            hi = xi1 - xi
            dx = x_val - xi
            return ai + bi * dx + ci * dx**2 + di * dx**3

# Вычисление коэффициентов сплайна
coefficients = calculate_spline_coefficients(x, y)

# Вычисление значения сплайна в точке x=1.5
x_val = 1.5
spline_val = spline_value(x, x_val, coefficients)
print(f"Значение сплайна в точке x={x_val}: {spline_val}")
