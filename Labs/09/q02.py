import matplotlib.pyplot as plt

cities = ['New York', 'Los Angeles', 'Chicago', 'Houston', 'Phoenix']
populations = [1419600, 980400, 1716000, 1328000, 690000]

# plt.xa
plt.figure(figsize=(11, 6))

plt.xlabel("Populations", fontsize=20)
plt.ylabel("Cities", fontsize=20)

plt.barh(cities, populations, height=0.5)
plt.show()