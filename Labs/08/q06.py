import numpy as np

# below line will produce error as shapes of matrices are different
arr = np.random.randint(1, 100, (5, 3)) * np.random.randint(1, 100, (3, 2))

print(arr)
