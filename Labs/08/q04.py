import numpy as np

data_types = [("name", "S15"), ("class", int), ("height", float)]

student_details = [("Umar", 7, 5.7), ("Fahad", 8, 5.7), ("Abdul Rahman", 7, 5.9), ("Talha", 6, 5.8)]

students = np.array(student_details, dtype=data_types)

print("Before sorting:")
print(students)

print("\nAfter sorting:")
print(np.sort(students, order=["class", "height"]))
