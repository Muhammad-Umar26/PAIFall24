num1 = int(input("Enter first number : "))
num2 = int(input("Enter second number : "))

operation = input("Enter operation you want to perform (+, -, *, /): ")
ans = 0

match operation:
    case '+':
        print("\nAnswer :", num1 - (-num2))

    case '-':
        print("\nAnswer :", num1 - num2)

    case '*':
        print("\nAnswer :", num1 * num2)

    case '/':
        print("\nAnswer :", num1 / num2)
