try:
    name = input("Enter biodata of employee\nName : ")
    cnic = input("CNIC : ")
    age = int(input("Age : "))
    salary = int(input("Salary : "))

    f = open("q04.txt", 'w')
    f.write(f"Name: {name}\nCNIC: {cnic}\nAge: {age}\nSalary: {salary}")
    f.close()

    conNum = input("Contact Number : ")

    f = open("q04.txt", 'a')
    f.write(f"\nContact Number: {conNum}")
    f.close()

    f = open("q04.txt")
    print("\nReading from file\n" + f.read())
    f.close()

except Exception as e:
    print(str(e))
