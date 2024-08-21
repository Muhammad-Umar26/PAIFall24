word = input("Enter any word : ")
reversed = ""

for i in range(len(word) - 1, -1, -1):
    reversed += word[i]

print("Reversed :", reversed)
