import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("Students data.csv")

df = df.head(10)

plt.figure(figsize=(9, 6))

plt.scatter(df['ID'], df['Mathematics'], color='b', label='Mathematics')
plt.scatter(df['ID'], df['Science'], color='r', label='Science')

plt.xticks(df['ID'])
plt.xlabel('IDs', fontsize=18)
plt.ylabel('Marks', fontsize=18)
plt.title("Comparision Between marks of Science and Mathematics", fontsize=20)
plt.legend()

plt.show()