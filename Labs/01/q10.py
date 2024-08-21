myList = []

size = int(input("Enter the size of list : "))

for i in range(size):
    myList.append(int(input(f"Enter number {i + 1} : ")))

largest = myList[0]

for i in range(1, size):
    largest = max(largest, myList[i])

print("\nLargest number in list :", largest)
