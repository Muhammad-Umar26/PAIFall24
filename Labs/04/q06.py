class BankAccount:
    def __init__(self, account_number, balance, date_of_opening, customer_name):
        self.account_number = account_number
        self.balance = balance
        self.date_of_opening = date_of_opening
        self.customer_name = customer_name

    def deposit(self, amount):
        self.balance += amount

    def withdraw(self, amount):
        if amount <= self.balance:
            self.balance -= amount
        else:
            print("Sorry! You have not much balance")

    def check_balance(self):
        return self.balance
    
    def print_data(self):
        print(f"Account Number : {self.account_number}\nBalance : {self.balance}\nDate of opening : {self.date_of_opening}\nCustomer Name : {self.customer_name}")
    
b = BankAccount("001", 30000, "11/09/2024", "Umar")
b.print_data()
b.deposit(10000)
print("\nBalance after depositing 10000 :", b.check_balance())
b.withdraw(20000)
print("Balance after withdrawing 20000 :", b.check_balance())
