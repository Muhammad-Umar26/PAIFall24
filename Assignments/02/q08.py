import numpy as np

# Coefficient matrix
A = np.array([[2, 3, -1],
              [-3, 4, 2],
              [1, -1, 3]])

# Constant terms
B = np.array([5, 6, 4])

# Solve for [x, y, z]
solution = np.linalg.solve(A, B)

print("Solution:", solution)
