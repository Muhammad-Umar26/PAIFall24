def convertCurrency(amount, rate):
    return amount * rate

currency1 = input("Which curreny you want to convert? (Euro, Dollar, PKR, INR, yen) : ")
amount = float(input("Enter amount you want to convert : "))
currency2 = input("In which currency you want to convert? (Euro, Dollar, PKR, INR, yen) : ")

rates = {
    "Euro": {"Dollar": 1.11, "PKR": 309.48, "INR": 98.23, "yen": 160.81},
    "Dollar": {"Euro": 0.9, "PKR": 278.62, "INR": 83.94, "yen": 144.74},
    "PKR": {"Euro": 0.0032, "Dollar": 0.0036, "INR": 0.3, "yen": 0.52},
    "INR": {"Euro": 0.011, "Dollar": 0.012, "PKR": 3.32, "yen": 1.72},
    "yen": {"Euro": 0.0062, "Dollar": 0.0069, "PKR": 1.93, "INR": 0.58}
}

print()
print(amount, currency1, "equals", convertCurrency(amount, rates[currency1][currency2]), currency2)
