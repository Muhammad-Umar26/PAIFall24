myList = []

size = int(input("Enter the size of list : "))

for i in range(size):
    myList.append(int(input(f"Enter num {i + 1} : ")))

n = int(input("\nEnter the number : "))

print("\nList before deletion :", myList)

myList2 = [num for num in myList if num >= n]

print("List after deletion :", myList2)
