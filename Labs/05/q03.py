class Account:
    def set_data(self, account_no, account_bal, security_code):
        self.__account_no = account_no
        self.__account_bal = account_bal
        self.__security_code = security_code

    def print_data(self):
        print(f"Account Number : {self.__account_no}\nBalance : {self.__account_bal}\nSecurity Code : {self.__security_code}")

account = Account()
account.set_data("001", 40000, "A1B2C3")
account.print_data()
