class Restaurant:
    def __init__(self):
        self.menu_items = {}
        self.book_tables = {}
        self.customer_orders = {}

    def add_item_to_menu(self, itemName, itemPrice):
        self.menu_items[itemName] = itemPrice

    def book_table(self, tableNo, customerName):
        self.book_tables[tableNo] = customerName

    def customer_order(self, customerName, order):
        self.customer_orders[customerName] = order

    def print_menu(self):
        print("Menu")
        for item, price in self.menu_items.items():
            print(f"{item} : {price}")

    def print_table_reservations(self):
        print("Table reservations")
        for tableNo, customerName in self.book_tables.items():
            print(f"{tableNo} has been booked by {customerName}")

    def print_customer_orders(self):
        print("Customer orders")
        for customerName, order in self.customer_orders.items():
            print(f"{customerName} has ordered {order}")

restaurant = Restaurant()

restaurant.add_item_to_menu("Pizza", 700)
restaurant.add_item_to_menu("Fries", 100)
restaurant.add_item_to_menu("Burger", 400)
restaurant.add_item_to_menu("Roll", 200)
restaurant.add_item_to_menu("Icecream", 150)

restaurant.book_table(2, "Umar")
restaurant.book_table(3, "Umar")
restaurant.book_table(5, "Fahad")
restaurant.book_table(8, "Ali")

restaurant.customer_order("Umar", "Burger")
restaurant.customer_order("Fahad", "Roll")
restaurant.customer_order("Ali", "Pizza")

restaurant.print_menu()
print()

restaurant.print_table_reservations()
print()

restaurant.print_customer_orders()
