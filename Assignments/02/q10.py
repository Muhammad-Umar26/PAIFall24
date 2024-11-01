import numpy as np

def normalize(arr):
    mean = np.mean(arr)
    std_dev = np.std(arr)
    normalized_arr = (arr - mean) / std_dev
    return normalized_arr

arr = np.array([1, 2, 3, 4, 5])
print("Array :", arr)

normalized_arr = normalize(arr)
print("\nNormalized array :", normalized_arr)