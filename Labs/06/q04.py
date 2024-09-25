import pandas as pd

df = pd.read_csv('heart.csv')
df = df.set_index('age')

print(df)
