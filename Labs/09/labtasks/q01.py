import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("iris.csv")

list1 = list(df["sepal_length"])
list2 = list(df["petal_length"])

plt.plot(list1, list2, color = 'r')
plt.xlabel("Sepal Length")
plt.ylabel("Petal Length")

plt.show()
