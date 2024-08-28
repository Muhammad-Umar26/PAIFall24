def areaOfTrapezoid(a, b, h):
    return ((a + b) / 2) * h

def areaOfParalleologram(b, h):
    return b * h

def areaOfCylinder(r, h):
    return (2 * 3.14 * r) * (h + r)

def surfaceVolumeOfCylinder(r, h):
    return 2 * 3.14 * r * h

side1 = float(input("Enter length of side 1 of trapezoid : "))
side2 = float(input("Enter length of side 2 of trapezoid : "))
height1 = float(input("Enter height of trapezoid : "))

base = float(input("\nEnter base of parallelogram : "))
height2= float(input("Enter height of parallelogram : "))

radius = float(input("\nEnter radius of cylinder : "))
height3 = float(input("Enter height of cylinder : "))

print("\nArea of trapezoid :", areaOfTrapezoid(side1, side2, height1))
print("Area of paralleologram :", areaOfParalleologram(base, height2))
print("Area of cylinder :", areaOfCylinder(radius, height3))
print("Area of trapezoid :", surfaceVolumeOfCylinder(radius, height3))
