import random
import math

# Уравнение эллипса: (x-h)^2/a^2 + (y-k)^2/b^2 = 1
# где (h, k) - центр эллипса, a - длина большой полуоси, b - длина малой полуоси

def random_point():
    return random.uniform(-10, 10), random.uniform(-10, 10)

# Случайные параметры эллипса и точки
h, k = random_point()
a = random.uniform(1, 10)
b = random.uniform(1, a)
x, y = random_point()

# Проверка принадлежности точки эллипсу
def is_point_on_ellipse(x, y, h, k, a, b):
    return ((x - h)**2 / a**2) + ((y - k)**2 / b**2) <= 1

# Координаты фокусов эллипса
def ellipse_foci(h, k, a, b):
    c = math.sqrt(a**2 - b**2)
    return (h + c, k), (h - c, k)

# Эксцентриситет эллипса
def ellipse_eccentricity(a, b):
    return math.sqrt(1 - (b**2 / a**2))

# Расстояние от директрис эллипса до его центра
def ellipse_directrix_distance(a, b):
    e = ellipse_eccentricity(a, b)
    return a / e

# Вычисления
point_on_ellipse = is_point_on_ellipse(x, y, h, k, a, b)
foci1, foci2 = ellipse_foci(h, k, a, b)
eccentricity = ellipse_eccentricity(a, b)
directrix_distance = ellipse_directrix_distance(a, b)

# Вывод результатов
print(f"Параметры эллипса: центр = ({h}, {k}), большая полуось = {a}, малая полуось = {b}")
print(f"Координаты точки: ({x}, {y})")
print(f"Точка принадлежит эллипсу: {'Да' if point_on_ellipse else 'Нет'}")
print(f"Фокусы эллипса: ({foci1[0]}, {foci1[1]}) и ({foci2[0]}, {foci2[1]})")
print(f"Эксцентриситет эллипса: {eccentricity}")
print(f"Расстояние от директрис до центра эллипса: {directrix_distance}")
