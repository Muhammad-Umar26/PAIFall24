def convertUrl(url):
    return url[11:len(url)]

url = input("Enter url that starts with 'http://www.' : ")
print("Converted URL :", convertUrl(url))
