try:
    f = open("file.txt")
    content = f.read()
    f.close()

    f = open("file.txt", 'w')
    content = content.replace("Artficial Intelligence", "Computer Science")
    f.write(content)
    f.close()

except FileNotFoundError:
    print("Error: The file 'file.txt' was not found.")
