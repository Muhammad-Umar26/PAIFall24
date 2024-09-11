class Vehicle:
    def __init__(self, seating_capacity):
        self.seating_capacity = seating_capacity
        self.fare = self.seating_capacity * 100

class Bus(Vehicle):
    def __init__(self, seating_capacity):
        super().__init__(seating_capacity)
        self.fare += self.fare * 0.1
    
bus = Bus(55)
print("Total fare :", bus.fare)
