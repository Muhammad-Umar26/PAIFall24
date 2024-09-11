class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def print_biodata(self):
        print("Name :", self.name)
        print("Age :", self.age)

s = Student("Muhammad Umar", 20)
s.print_biodata()
