from abc import ABC, abstractmethod

class Employee(ABC):
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary

    @abstractmethod
    def calculateBonus(self):
        pass

class Manager(Employee):
    def __init__(self, name, salary):
        super().__init__(name, salary)

    def calculateBonus(self):
        print(f"{self.name} will get bonus of Rs.", 0.2 * self.salary)

    def hire(self):
        print(f"{self.name} is hiring")

class Developer(Employee):
    def __init__(self, name, salary):
        super().__init__(name, salary)

    def calculateBonus(self):
        print(f"{self.name} will get bonus of Rs.", 0.1 * self.salary)

    def writeCode(self):
        print(f"{self.name} is writing code")

class SeniorManager(Manager):
    def __init__(self, name, salary):
        super().__init__(name, salary)

    def calculateBonus(self):
        print(f"{self.name} will get bonus of Rs.", 0.3 * self.salary)

developer = Developer("Talha", 50000)
manager = Manager("Umar", 60000)
seniorManager = SeniorManager("Fahad", 70000)

developer.writeCode()
developer.calculateBonus()
print()

manager.hire()
manager.calculateBonus()
print()

seniorManager.hire()
seniorManager.calculateBonus()
