import json

try:
    dic = {}

    size = int(input("Enter total number of people : "))

    for i in range(size):
        name = input(f"Enter name of person {i + 1} : ")
        age = int(input(f"Enter age of person {i + 1} : "))
        dic[name] = age
        print()

    f = open("q05.json", 'w')
    json.dump(dic, f)
    f.close()

    f = open("q05.json")
    dic2 = json.load(f)
    f.close()

    maxAge = 0
    maxAgeName = ""
    for name in dic2:
        if dic2[name] > maxAge:
            maxAge = dic2[name]
            maxAgeName = name

    print(f"{maxAgeName} has the age {maxAge} which is maximum\n")

    sameAgeGroups = []
    visited = []
    for name1 in dic2:
        if name1 not in visited:
            temp = [name1]
            for name2 in dic2:
                if name1 != name2 and dic2[name1] == dic2[name2] and name2 not in visited:
                    temp.append(name2)
                    visited.append(name2)

            if len(temp) > 1:
                sameAgeGroups.append(temp)
                
            visited.append(name1)

    for sameAgeGroup in sameAgeGroups:
        names = ""
        for person in sameAgeGroup:
            names += person + ", "
        
        names = names[:-2]
        print(names + " have the age", dic2[sameAgeGroup[0]])

except Exception as e:
    print(str(e))