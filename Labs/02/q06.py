def multilpyNumbersInList(myList):
    ans = 1
    for num in myList:
        ans *= num
    return ans

myList = [1, 2, 3, 4, 5]

print("Multiplied value :", multilpyNumbersInList(myList))
