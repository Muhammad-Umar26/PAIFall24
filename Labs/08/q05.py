import numpy as np

arr = (np.random.choice([2, 5, 9, 10], size=(4, 4)) * np.eye(4)) + np.arange(1, 33, 2).reshape(4, 4)

print(arr)
