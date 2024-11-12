import matplotlib.pyplot as plt

students = ["Umar", "Fahad", "Raghib", "Abdul Rahman", "Saif", "Talha", "Ali", "Fasih", "Owais", "Abser", "John", "Mubeen", "Salman", "Hasan", "Farhan", "Sadiq", "Hammad", "Shaheer", "Khan", "Nasir"]
heights = [5.75, 5.7, 5.4, 5.9, 5.6, 5.7, 5.72, 5.68, 5.65, 5.9, 5.6, 5.4, 5.44, 5.51, 5.6, 5.8, 6, 6.1, 5.95, 5.65]

plt.figure(figsize=(12, 6))

plt.xlabel("Students", fontsize=20)
plt.ylabel("Heights", fontsize=20)
plt.title("Student Data", fontsize=28)
plt.xticks(rotation=90)
plt.bar(students, heights, width=0.6)
plt.show()

plt.pie(heights, labels=students)
plt.show()