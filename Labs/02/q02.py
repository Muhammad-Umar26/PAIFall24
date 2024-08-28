def isLastLetterVowel(word):
    return word[-1] == 'a' or word[-1] == 'e' or word[-1] == 'i' or word[-1] == 'o' or word[-1] == 'u'

word = input("Enter any word : ")

print("Last letter is", "vowel" if isLastLetterVowel(word) else "consonant")
