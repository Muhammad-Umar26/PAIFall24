import numpy as np

arr = np.arange(25)
print("Array :", arr)

percentile_75th = np.percentile(arr, 75)
print("\n75th percentile :", percentile_75th)