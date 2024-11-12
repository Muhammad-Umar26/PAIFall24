import matplotlib.pyplot as plt
import numpy as np

ages = np.array([18, 19, 20, 22, 25, 21, 24, 26, 28, 27, 29, 30, 32, 33, 34, 31, 35, 36, 37, 38, 40, 42, 39, 45, 43, 41, 19, 21, 23, 26, 28, 33, 30, 22, 24, 29, 20, 18, 25, 27, 36, 40, 38, 26, 31, 34, 32, 45])

age_group_names = ['18-25', '26-30', '31-35', '36 and above']
age_groups = [len(ages[(ages >= 18) & (ages <= 25)]), len(ages[(ages >= 26) & (ages <= 30)]), len(ages[(ages >= 31) & (ages <= 35)]), len(ages[ages >= 36])]

plt.pie(age_groups, labels=age_group_names, autopct='%1.2f%%', startangle=90)
plt.title('Distribution of Student Ages')
plt.show()