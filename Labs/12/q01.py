import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

df = pd.read_csv("Iris.csv")

numerical_features = ['SepalLengthCm', 'SepalWidthCm', 'PetalLengthCm', 'PetalWidthCm']
data = df[numerical_features]

scaler = StandardScaler()
data_scaled = scaler.fit_transform(data)

pd.DataFrame(data_scaled, columns=numerical_features)

xtrain, xtest = train_test_split(data_scaled, test_size=0.5, random_state=42)

inertias = []
for cluster in range(1, 20):
    kmeans = KMeans(n_clusters=cluster, init='k-means++')
    kmeans.fit(data_scaled)
    inertias.append(kmeans.inertia_)

plt.figure(figsize=(12, 6))
plt.plot(range(1, 20), inertias, marker='o')
plt.xlabel('Number of clusters')
plt.ylabel('Inertias')
plt.show()

kmeans = KMeans(n_clusters=3, init = 'k-means++')
kmeans.fit(data_scaled)
pred = kmeans.predict(data_scaled)

frame = pd.DataFrame(data_scaled)
frame['cluster'] = pred
print(frame['cluster'].value_counts())
