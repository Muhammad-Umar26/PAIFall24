try:
    f = open("q01.txt")
    content = f.read()

    characterCount = len(content)
    wordCount = len(content.split())
    
    print("Number of characters in file :", characterCount, "\nNumber of words in file :", wordCount)

    f.close()

except Exception as e:
    print(str(e))
