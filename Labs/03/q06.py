question = input("Enter any sentence : ")

if question[-1] == '?':
    f = open("file.txt", 'w')
    
    f.write(question)

    f.close()

    print("Question written in file successfully")
    
else: 
    print("Given sentence is not a question")
