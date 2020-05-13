"""Наилучшее среднеквадратичное приближние"""

import numpy as np
import matplotlib.pyplot as plt
from operator import mul, sub


def fi(x, k):
    return x ** k


def print_result(table, A, n):
    dx = 10
    if len(table) > 1:
        dx = (table[1][0] - table[0][0])

    x = np.linspace(table[0][0] - dx, table[-1][0] + dx, 1000)
    y = []
    for i in x:
        tmp = 0;
        for j in range(0, n + 1):
            tmp += fi(i, j) * A[j]
        y.append(tmp)

    plt.plot(x, y)

    x1 = [a[0] for a in table]
    y1 = [a[1] for a in table]

    plt.plot(x1, y1, 'kD', color='green', label='$таблица$')
    plt.grid(True)
    plt.legend(loc='best')
    miny = min(min(y), min(y1))
    maxy = max(max(y), max(y1))
    dy = (maxy - miny) * 0.03
    plt.axis([table[0][0] - dx, table[-1][0] + dx, miny - dy, maxy + dy])

    plt.show()
    return


def read_from_file(file_name):
    data = []
    f = open(file_name, "r")
    for line in f:
        if line:
            a, b, c = map(float, line.split())
            data.append([a, b, c])
    f.close()
    return data


def get_slau_matrix(table, n):
    N = len(table)
    matrix = [[0 for i in range(0, n + 1)] for j in range(0, n + 1)]
    col = [0 for i in range(0, n + 1)]

    for m in range(0, n + 1):
        for i in range(0, N):
            tmp = table[i][2] * fi(table[i][0], m)
            for k in range(0, n + 1):
                matrix[m][k] += tmp * fi(table[i][0], k)
            col[m] += tmp * table[i][1]
    return matrix, col


def Gauss(matr):
    n = len(matr)

    for k in range(n):
        for i in range(k + 1, n):
            coeff = -(matr[i][k] / matr[k][k])
            for j in range(k, n + 1):
                matr[i][j] += coeff * matr[k][j]

    a = [0 for i in range(n)]
    for i in range(n - 1, -1, -1):
        for j in range(n - 1, i, -1):
            matr[i][n] -= a[j] * matr[i][j]
        a[i] = matr[i][n] / matr[i][i]
    return a


def det(b):
    res = 1
    a = b
    n = len(a)
    for i in range(n):
        j = max(range(i, n), key=lambda k: abs(a[k][i]))
        if i != j:
            a[i], a[j] = a[j], a[i]
            res *= -1
        if a[i][i] == 0:
            return 0
        res *= a[i][i]
        for j in range(i + 1, n):
            b = a[j][i] / a[i][i]
            a[j] = [a[j][k] - b * a[i][k] for k in range(n)]
    return res


def get_approx_coef(table, n):
    m, z = get_slau_matrix(table, n)

    for i in range(len(z)):
        m[i].append(z[i])
    ma = list(m)
    det_m = det(ma)
    if abs(det_m) > 0.0000001:
        a_array = Gauss(m)
        return a_array
    else:
        print("Определитель матрицы равен нулю")
        return None


table = read_from_file("table.txt")
print("Таблица:")
print("  X    Y")
for i in range(len(table)):
    print(table[i][:2])

n = int(input("Введите степень аппроксимирующей функции = "))
A = get_approx_coef(table, n)

if A != None:
    print_result(table, A, n)
