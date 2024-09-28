import math as m
import numpy as np
def vector(vec, xvec, yvec, zvec):
    magnitude = np.linalg.norm(vec)
    print("Magnitude of Vector A =", magnitude)
    return m.acos(np.dot(vec, xvec) / magnitude), m.acos(np.dot(vec, yvec) / magnitude), m.acos(np.dot(vec, zvec) / magnitude)
ax = float(input("Enter Axi: "))
ay = float(input("Enter Ayj: "))
az = float(input("Enter Azk: "))
A = np.array([ax, ay, az])
B = np.array([1, 0, 0])
C = np.array([0, 1, 0])
D = np.array([0, 0, 1])
a, b, g = vector(A, B, C, D)
print("Alpha =", str(m.degrees(a)) + "\u00b0")
print("Beta =", str(m.degrees(b)) + "\u00b0")
print("Gamma =", str(m.degrees(g)) + "\u00b0")