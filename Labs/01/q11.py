dict = {}

for i in range(3):
    dict[f"Subject {i + 1}"] = int(input(f"Enter obtained marks in subject {i + 1} : "))

sum = 0
for subject in dict:
    sum += dict[subject]

print("\nAverage marks : ", round(sum / 3, 2))
print("Percentage : ", round((sum / 300) * 100, 2))
