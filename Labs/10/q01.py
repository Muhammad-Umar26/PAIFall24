import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

df = pd.read_csv("heart.csv")

plt.figure(figsize=(10, 8))

plt.subplot(4, 4, 1)
plt.hist(df['age'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('AGE')

plt.subplot(4, 4, 2)
plt.hist(df['sex'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('SEX')

plt.subplot(4, 4, 3)
plt.hist(df['cp'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('CP')

plt.subplot(4, 4, 4)
plt.hist(df['trestbps'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('TRESTBPS')

plt.subplot(4, 4, 5)
plt.hist(df['chol'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('Chol')

plt.subplot(4, 4, 6)
plt.hist(df['fbs'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('FBS')

plt.subplot(4, 4, 7)
plt.hist(df['restecg'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('RESTECG')

plt.subplot(4, 4, 8)
plt.hist(df['thalach'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('THALACH')

plt.subplot(4, 4, 9)
plt.hist(df['exang'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('EXANG')

plt.subplot(4, 4, 10)
plt.hist(df['oldpeak'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('OLDPEAK')

plt.subplot(4, 4, 11)
plt.hist(df['slope'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('SLOPE')

plt.subplot(4, 4, 12)
plt.hist(df['ca'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('CA')

plt.subplot(4, 4, 13)
plt.hist(df['thal'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('THAL')

plt.subplot(4, 4, 14)
plt.hist(df['target'], bins=10, color='blue', edgecolor='black', alpha=0.7)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('TARGET')

plt.tight_layout()
plt.show()

plt.figure(figsize=(12, 10))

sns.heatmap(data=df.corr(), annot=True, cmap='coolwarm', fmt='.2f', square=True, linewidths=0.3)
plt.title('Correlation Heatmap')

plt.show()

plt.pie(df['sex'].value_counts(), labels=['male', 'female'], autopct="%1.1f%%")
plt.title('Distribution of Sex')
plt.show()

sns.displot(df, x='chol',kde=True)
sns.displot(df, x='thalach',kde=True)
sns.displot(df, x='age',kde=True)
sns.displot(df, x='trestbps',kde=True)
plt.show()
