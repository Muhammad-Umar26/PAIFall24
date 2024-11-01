import numpy as np

matrix = np.random.randint(1, 100, (3, 3))
print("Matrix :\n", matrix, sep="")

transpose = np.transpose(matrix)
print("\nTranspose of Matrix :\n", transpose, sep="")