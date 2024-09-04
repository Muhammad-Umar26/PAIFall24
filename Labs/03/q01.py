try:
    f = open("file.txt")
    content = f.read()

    characterCount = len(content)
    wordCount = len(content.split())
    
    print("Number of characters in file :", characterCount, "\nNumber of words in file :", wordCount)

    f.close()

except FileNotFoundError:
    print("Error: The file 'file.txt' was not found.")
