from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        print("dfhg")

class Rectangle(Shape):
    def area(self, length, width):
        print("Area of rectangle with length", length, "units and width", width, "units is", length * width, "sq. units")

class Triangle(Shape):
    def area(self, base, height):
        print("Area of triangle with base", base, "units and width", height, "units is", 0.5 * base * height, "sq. units")

class Square(Shape):
    def area(self, sideLength):
        print("Area of square with side length", sideLength, "units is", sideLength * sideLength, "sq. units")

rect = Rectangle()
rect.area(3, 4)

triangle = Triangle()
triangle.area(6, 7)

square = Square()
square.area(5)
