name = input("Enter biodata of employee\nName : ")
cnic = input("CNIC : ")
age = int(input("Age : "))
salary = int(input("Salary : "))

f = open("file.txt", 'w')

f.write(f"Name: {name}\nCNIC: {cnic}\nAge: {age}\nSalary: {salary}")

f.close()

conNum = input("Contact Number : ")

f = open("file.txt", 'a')

f.write(f"\nContact Number: {conNum}")

f.close()

try:
    f = open("file.txt")
    
    print("\nReading from file\n" + f.read())

    f.close()

except FileNotFoundError:
    print("Error: The file 'file.txt' was not found.")
