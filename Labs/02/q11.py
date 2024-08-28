def add_new_grade(grades, studName, grade):
    if studName not in grades:
        add_new_student(grades, studName)
    grades[studName].append(grade)

def average_grade_of_specific_student(grades, studName):
    print("Average grade of", studName, ":", sum(grades[studName]) / len(grades[studName]))

def add_new_student(grades, studName):
    grades.update({studName: []})

def remove_student(grades, studName):
    grades.pop(studName)

grades = {}

add_new_student(grades, "Alice")
add_new_student(grades, "Bob")
add_new_student(grades, "John")
    
# Add new grades for students
add_new_grade(grades, "Alice", 85)
add_new_grade(grades, "Alice", 90)
add_new_grade(grades, "Alice", 82)
add_new_grade(grades, "Bob", 78)
add_new_grade(grades, "Bob", 82)
add_new_grade(grades, "John", 95)

# Print average grades
average_grade_of_specific_student(grades, "Alice")
average_grade_of_specific_student(grades, "Bob")

# Remove a student
remove_student(grades, "John")

print("Grades Now :", grades)
