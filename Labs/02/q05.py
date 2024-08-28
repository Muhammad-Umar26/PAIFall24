def factorial(n):
    if n <= 2:
        return n
    return n * factorial(n - 1)

n = int(input("Enter number : "))
print("Factorial of", n, ":", factorial(n))
