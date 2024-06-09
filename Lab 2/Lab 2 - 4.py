import random
import math

# Уравнение двуполостного гиперболоида: x^2/a^2 + y^2/b^2 - z^2/c^2 = -1
# Плоскость: Ax + By + Cz + D = 0
# Прямая: x = x0 + t*lx, y = y0 + t*ly, z = z0 + t*lz
# Точка: (px, py, pz)

def random_point_3d():
    return random.uniform(-10, 10), random.uniform(-10, 10), random.uniform(-10, 10)

# Случайные параметры гиперболоида, плоскости, прямой и точки
a, b, c = random.uniform(1, 10), random.uniform(1, 10), random.uniform(1, 10)
A, B, C, D = random.uniform(-10, 10), random.uniform(-10, 10), random.uniform(-10, 10), random.uniform(-10, 10)
x0, y0, z0 = random_point_3d()
lx, ly, lz = random.uniform(-1, 1), random.uniform(-1, 1), random.uniform(-1, 1)
px, py, pz = random_point_3d()

# Проверка принадлежности точки гиперболоиду
def is_point_on_hyperboloid(px, py, pz, a, b, c):
    return (px**2 / a**2) + (py**2 / b**2) - (pz**2 / c**2) <= -1

# Проверка пересечения плоскости и гиперболоида
def does_plane_intersect_hyperboloid(A, B, C, D, a, b, c):
    discriminant = (A**2 / a**2) + (B**2 / b**2) - (C**2 / c**2)
    return discriminant > 0

# Проверка пересечения прямой и гиперболоида
def does_line_intersect_hyperboloid(x0, y0, z0, lx, ly, lz, a, b, c):
    A = (lx**2 / a**2) + (ly**2 / b**2) - (lz**2 / c**2)
    B = 2 * ((x0 * lx / a**2) + (y0 * ly / b**2) - (z0 * lz / c**2))
    C = (x0**2 / a**2) + (y0**2 / b**2) - (z0**2 / c**2) - 1
    discriminant = B**2 - 4 * A * C
    return discriminant >= 0

# Вычисления
point_on_hyperboloid = is_point_on_hyperboloid(px, py, pz, a, b, c)
plane_intersects_hyperboloid = does_plane_intersect_hyperboloid(A, B, C, D, a, b, c)
line_intersects_hyperboloid = does_line_intersect_hyperboloid(x0, y0, z0, lx, ly, lz, a, b, c)

# Вывод результатов
print(f"Параметры гиперболоида: a = {a}, b = {b}, c = {c}")
print(f"Параметры плоскости: A = {A}, B = {B}, C = {C}, D = {D}")
print(f"Параметры прямой: (x0, y0, z0) = ({x0}, {y0}, {z0}), (lx, ly, lz) = ({lx}, {ly}, {lz})")
print(f"Координаты точки: ({px}, {py}, {pz})")
print(f"Точка принадлежит гиперболоиду: {'Да' if point_on_hyperboloid else 'Нет'}")
print(f"Плоскость пересекает гиперболоид: {'Да' if plane_intersects_hyperboloid else 'Нет'}")
print(f"Прямая пересекает гиперболоид: {'Да' if line_intersects_hyperboloid else 'Нет'}")
