try:
    f = open("q02.txt")
    content = f.read()
    f.close()

    f = open("q02.txt", 'w')
    content = content.replace("Artificial Intelligence", "Computer Science")
    f.write(content)
    f.close()

except Exception as e:
    print(str(e))
