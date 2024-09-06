try:
    num1 = int(input("Enter the first number : "))
    num2 = int(input("Enter the second number : "))

    print(f"\n{num1} / {num2} = {num1 / num2}")

except ZeroDivisionError:
    print("\nError: Division by zero is not allowed.")

except ValueError:
    print("\nError: Please enter valid integer numbers.")
