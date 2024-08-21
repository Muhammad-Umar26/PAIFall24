myList = []

size = int(input("Enter the size of list : "))
count = 0

for i in range(size):
    myList.append(int(input(f"Enter num {i + 1} : ")))
    if myList[i] % 2 == 0:
        count += 1

print("Total count of even numbers in list :", count)
