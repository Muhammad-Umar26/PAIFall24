import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("Global Sea Level Rise.csv")

df = df.tail(100)

plt.figure(figsize=(9, 6))

plt.scatter(df['year'], df['mmfrom1993-2008average'])
plt.xlabel('Year', fontsize=18)
plt.ylabel('Rise', fontsize=18)
plt.title("Sea Level Rise over past 100 years", fontsize=20)
plt.grid(True)

plt.show()