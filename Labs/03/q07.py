def correct_mistake_in_file():
    try:
        content = ""
        with open("replacement_needed.txt") as f:
            content = f.read()

        print(content)

        word = input("\nEnter the word in which you want to make corrections : ")
        wrongLetter = input("Enter the letter that needs to be replaced : ")
        correctLetter = input("Enter the letter you want to replace it with : ")

        with open("replacement_needed.txt", 'w') as f:
            f.write(content.replace(word, word.replace(wrongLetter, correctLetter)))

        print("\nThe mistake has been corrected successfully")

    except Exception as e:
        print(str(e))

correct_mistake_in_file()