dict = {}

dict["Physics"] = int(input("Enter physics marks : "))
dict["Chemistry"] = int(input("Enter physics marks : "))
dict["Maths"] = int(input("Enter physics marks : "))

sum = 0
highestMarks = -1
highestSubject = ""

for x in dict:
    sum += dict[x]

    if dict[x] > highestMarks:
        highestMarks = dict[x]
        highestSubject = x

print("\nAverage marks :", sum / len(dict))
print("Highest marks are in subject :", highestSubject)
