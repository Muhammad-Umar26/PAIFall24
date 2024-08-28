# def cal(val1,val2,oper):
#     if(oper == '+'): return val1+val2
#     elif (oper == '-'): return val1 - val2
#     elif (oper == '/'): return val1 / val2
#     elif (oper == '*'): return val1 * val2
#     else : print("wrong Operation")


#print(f"Ans: { cal(2,2,'+')}")

#PT 1
def greeting():
    print("Start Code: ")

greeting()



#PT 2


def calculatearea(l,w):
    return l*w

l= int(input("Enter length: "))
w= int(input("Enter width: "))



b = calculatearea(l,w)
print("ANS: ", b)


#PT 4

def show_info(**details):
    print(f"Name: {details["name"]}, Age: {details["age"]},")


show_info(name = "FAHAD", age= 19)


#PT 3

def find_maximum(*numbers):
    print(max(numbers))

find_maximum(9,7,10,56,9)


#String PT 1

name = input("Enter Your Goodname! ")
reply = input(f"Hello! {name} \n I hope you are fine, let me know how I can help you!")
if(reply == "yes"):
    pb = input("share your problem with us")
    print("Thanks for your feedback,we will resolve your problem")
else:
    b = "Okay! Good to see you , stay connected"

    print(b.center(80))


#String PT 2

name = input("Enter Your name with cast ")
fname =  input("Enter Your father name  ")

data1 = name.split(" ")
data2 = fname.split(" ")

print(f"First Name: {data1[1]}, Last Name: {data2[1]}")
