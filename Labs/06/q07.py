import pandas as pd

df = pd.read_excel('employee.xlsx')

specificYear = int(input("Enter specific year for which you want to find employees : "))

print(df[df['Year'] == specificYear])