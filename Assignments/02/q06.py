import numpy as np

matrix = np.array([[1, 2], [3, 4]])

print("Matrix :", matrix, sep = "\n")

determinant = np.linalg.det(matrix)
print("\nDeterminat :", determinant)

inverse = np.linalg.inv(matrix)
print("\nInverse of Matrixx :", inverse, sep = "\n")