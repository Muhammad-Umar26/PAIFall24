import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("iris.csv")

df_count = df.groupby("species").size()

plt.bar(df_count.index, df_count.values, width = 0.5, color = ['r', 'b', 'g'])

plt.xlabel("Species")
plt.ylabel("Count")

plt.show()
