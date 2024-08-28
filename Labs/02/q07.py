def printAverage(temperatures):
    print("Average temperature : ", sum(temperatures) / len(temperatures))

def highestAndLowest(temperatures):
    print("\nHighest :", max(temperatures), "\nLowest :", min(temperatures))

temperatures = [22, 25, 19, 23, 21, 20, 24, 26, 28, 27, 25, 24, 22, 21, 20, 19, 23, 24, 26, 27, 28, 29, 30, 28, 27, 26, 25, 24, 23, 22]

print("Temperatures now :", temperatures, "\n")

printAverage(temperatures)

highestAndLowest(temperatures)

sorted = temperatures.copy()

sorted.sort()
print("\nTemperatures after sorting :", sorted)

temperatures.pop(4)
print("\nAfter removing data for 5th day :", temperatures)
