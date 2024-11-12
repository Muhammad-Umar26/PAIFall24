import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y1 = [10, 12, 15, 18, 20, 23, 25, 27, 30, 33]
y2 = [9, 11, 13, 17, 19, 21, 24, 26, 29, 31]

plt.plot(x, y1, color='pink', marker='o', label='Line 1')
plt.plot(x, y2, color='gray', marker='o', label= 'Line 2')

plt.title('Two Lines on One Graph', fontsize=18)
plt.xlabel('Amazing X-axis', fontsize=16)
plt.ylabel('Incredible Y-axis', fontsize=16)

plt.legend(loc='lower right')

plt.show()