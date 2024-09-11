class Employee:
    def get_data(self):
        self.name = input("Enter name of employee : ")
        self.salary = float(input("Enter salary : "))
        self.tax_percentage = float(input("Enter percentage of tax : "))
    
    def salary_after_tax(self):
        return self.salary - (self.tax_percentage / 100 * self.salary)
    
    def update_tax_percentage(self, new_percentage):
        self.tax_percentage = new_percentage

e = Employee()
e.get_data()
print(f"\nSalary after deducting {e.tax_percentage}% tax : {e.salary_after_tax()}")
e.update_tax_percentage(3)
print(f"Salary after deducting {e.tax_percentage}% tax : {e.salary_after_tax()}")
