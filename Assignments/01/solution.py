from abc import ABC, abstractmethod

class Animal(ABC):
    def __init__(self, name, age, habitat):
        self.name = name
        self.age = age
        self.habitat = habitat
        self.is_available = True

    def change_availability(self):
        self.is_available = not self.is_available
    
    @abstractmethod
    def displayDetails(self):
        print(f"Name : {self.name}\nAge : {self.age}\nHabitat : {self.habitat}\nStatus : {"Available" if self.is_available else "Quarantine"}")

class Mammals(Animal):
    def __init__(self, name, age, habitat, fur_length, diet_type):
        super().__init__(name, age, habitat)
        self.fur_length = fur_length
        self.diet_type = diet_type

    def displayDetails(self):
        super().displayDetails()
        print(f"Fur length : {self.fur_length}\nDiet type : {self.diet_type}\n")

class Birds(Animal):
    def __init__(self, name, age, habitat, wingspan, flight_altitude):
        super().__init__(name, age, habitat)
        self.wingspan = wingspan
        self.flight_altitude = flight_altitude

    def displayDetails(self):
        super().displayDetails()
        print(f"Wingspan : {self.wingspan}\nFlight altitude : {self.flight_altitude}\n")

class Reptiles(Animal):
    def __init__(self, name, age, habitat, scale_pattern, venomous_status):
        super().__init__(name, age, habitat)
        self.scale_pattern = scale_pattern
        self.venomous_status = venomous_status

    def displayDetails(self):
        super().displayDetails()
        print(f"Scale pattern : {self.scale_pattern}\nIs venomous : {"Yes" if self.venomous_status else "No"}\n")

elephant = Mammals("Elephant", 15, "Savannah", "Short", "Herbivore")
eagle = Birds("Eagle", 5, "Mountains", 2.0, 3000)
snake = Reptiles("Cobra", 3, "Desert", "Diamond", True)

print("Details of all animals in zoo :\n")
elephant.displayDetails()
eagle.displayDetails()
snake.displayDetails()

elephant.change_availability()
eagle.change_availability()
snake.change_availability()

print("After changing avaialbility of each animal :\n")
elephant.displayDetails()
eagle.displayDetails()
snake.displayDetails()
