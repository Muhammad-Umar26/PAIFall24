import matplotlib.pyplot as plt

flavors = ['Vanilla', 'Chocolate', 'Strawberry', 'Mint', 'Cookie Dough']
scoops_sold = [150, 200, 100, 80, 170]

plt.pie(scoops_sold, labels=flavors, autopct="%1.2f%%")
plt.show()