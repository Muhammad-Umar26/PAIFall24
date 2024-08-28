def build_message(**info):
    output = ""
    for currentInfo in info:
        output += f"{currentInfo} : {info[currentInfo]}\n"
    return output

print(build_message(Name = "Umar", Age = 20, City = "Karachi"))
