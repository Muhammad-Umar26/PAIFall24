class Student:
    def __init__(self, id, name):
        self.id = id
        self.name = name

    def displayInfo(self):
        print(f"Id : {self.id}\nName : {self.name}\n")

class Marks(Student):
    def __init__(self, id, name, marks_algo, marks_dataScience, marks_calculus):
        super().__init__(id, name)
        self.marks_algo = marks_algo
        self.marks_dataScience = marks_dataScience
        self.marks_calculus = marks_calculus

    def displayInfo(self):
        super().displayInfo()
        print(f"Algo Marks : {self.marks_algo}\nData Science Marks : {self.marks_dataScience}\nCalculus Marks : {self.marks_calculus}")

class Result(Marks):
    def __init__(self, id, name, marks_algo, marks_dataScience, marks_calculus):
        super().__init__(id, name, marks_algo, marks_dataScience, marks_calculus)

    def calculate(self):
        self.total = self.marks_algo + self.marks_dataScience + self.marks_calculus
        self.average = self.total / 3
    
    def displayInfo(self):
        super().displayInfo()
        print(f"\nTotal Marks : {self.total}\nAverage Marks : {self.average}")

result = Result("101", "Umar", 85, 90, 80)
result.calculate()
result.displayInfo()
