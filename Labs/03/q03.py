try:
    def take_input(size):
        thisList = []
        for i in range(size):
            thisList.append(input(f"Enter element {i + 1} : "))
        return thisList

    def make_dict(list1, list2):
        dic = {}
        for i in range(len(list1)):
            dic[list1[i]] = list2[i]
        return dic
    
    size = int(input("Enter total number of elements : "))

    print("\nEnter elements of list1")
    list1 = take_input(size)

    print("\nEnter elements of list2")
    list2 = take_input(size)

    f = open("file.txt", 'w')

    f.write(str(make_dict(list1, list2)))

    f.close()

except Exception as e:
    print(str(e))
