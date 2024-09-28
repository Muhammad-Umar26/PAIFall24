from abc import ABC, abstractmethod

class Vehicle(ABC):
    def __init__(self, make, model, rentalPrice):
        self.make = make
        self.model = model
        self._rentalPrice = rentalPrice
        self.availabiltyStatus = True

    def checkAvailability(self):
        return self.availabiltyStatus
    
    def calculateRent(self, hours):
        return self._rentalPrice * hours
    
    def displayDetails(self):
        print(f"Make : {self.make}\nModel : {self.model}\nRental price : {self._rentalPrice}\nAvailability status : {"Available" if self.availabiltyStatus else "Not available"}")

    @abstractmethod
    def bookVehicle(self):
        pass

    @abstractmethod
    def returnVehicle(self):
        pass

class Car(Vehicle):
    def __init__(self, make, model, rentalPrice):
        super().__init__(make, model, rentalPrice)

    def bookVehicle(self):
        if self.checkAvailability():
            self.availabiltyStatus = False
            print(f"Car with make {self.make} and model {self.model} is rented")
        else:
            raise Exception(f"Car with make {self.make} and model {self.model} is not available")

    def returnVehicle(self):
        if not self.checkAvailability():
            self.availabiltyStatus = True
            print(f"Car with make {self.make} and model {self.model} is returned")
        else:
            raise Exception(f"Car with make {self.make} and model {self.model} was not rented and is already available")

class SUV(Vehicle):
    def __init__(self, make, model, rentalPrice):
        super().__init__(make, model, rentalPrice)

    def bookVehicle(self):
        if self.checkAvailability():
            self.availabiltyStatus = False
            print(f"SUV with make {self.make} and model {self.model} is rented")
        else:
            raise Exception(f"SUV with make {self.make} and model {self.model} is not available")

    def returnVehicle(self):
        if not self.checkAvailability():
            self.availabiltyStatus = True
            print(f"SUV with make {self.make} and model {self.model} is returned")
        else:
            raise Exception(f"SUV with make {self.make} and model {self.model} was not rented and is already available")

class Truck(Vehicle):
    def __init__(self, make, model, rentalPrice):
        super().__init__(make, model, rentalPrice)

    def bookVehicle(self):
        if self.checkAvailability():
            self.availabiltyStatus = False
            print(f"Truck with make {self.make} and model {self.model} is rented")
        else:
            raise Exception(f"Truck with make {self.make} and model {self.model} is not available")

    def returnVehicle(self):
        if not self.checkAvailability():
            self.availabiltyStatus = True
            print(f"Truck with make {self.make} and model {self.model} is returned")
        else:
            raise Exception(f"Truck with make {self.make} and model {self.model} was not rented and is already available")

class Customer:
    def __init__(self, name, phoneNumber):
        self.name = name
        self.__phoneNumber = phoneNumber
        self.rentedVehicles = []

    def addRental(self, reservation):
        self.rentedVehicles.append(reservation)

    def displayRentalHistory(self):
        print(f"Rental history for {self.name}:")
        for reservation in self.rentedVehicles:
            reservation.displayDetails()

class RentalReservation:
    def __init__(self, customer, vehicle, startDate, endDate):
        self.startDate = startDate
        self.endDate = endDate
        self.customer = customer
        self.vehicle = vehicle

    def displayDetails(self):
        print(f"Customer name : {self.customer.name}\nVehicle : {self.vehicle.make} {self.vehicle.model}\nStart Date: {self.startDate}\nEnd Date: {self.endDate}")

def displayDetails(object):
    object.displayDetails()

car = Car("Toyota", "Corolla", 5000)
suv = SUV("Honda", "CR-V", 8000)
truck = Truck("Ford", "F-150", 10000)

displayDetails(car)
print()

displayDetails(suv)
print()

displayDetails(truck)
print()

customer = Customer("John Doe", "3580938539")

reservation = RentalReservation(customer, suv, "28-09-2024", "30-09-2024")
suv.bookVehicle()
customer.addRental(reservation)

displayDetails(reservation)
print()

customer.displayRentalHistory()
