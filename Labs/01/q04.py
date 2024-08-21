myList = []

size = int(input("Enter the size of list : "))
sum = 0

for i in range(size):
    myList.append(int(input(f"Enter num {i + 1} : ")))
    sum += myList[i]

print("Sum of all numbers in list :", sum)
