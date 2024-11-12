import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("Students data.csv")

plt.pie(df['gender'].value_counts(), labels=['Male', 'Female'], autopct="%1.2f%%")
plt.title('Gender Distribution', fontsize=20)
plt.show()