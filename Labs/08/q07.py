import numpy as np

arr = np.random.rand(1000)

average = np.average(arr)
variance = np.var(arr)
stddev = np.std(arr)

filename = "stats_file.txt"

with open(filename, 'w') as f:
    f.write(f"Average: {average}\nVariance: {variance}\nStandard Deviation: {stddev}")

print(f"Results saved in {filename}")
