def removeWhiteSpace(mystring):
    for i in range(len(myString)):
        if myString[i] == " " and myString[i + 1] == " ":
            newString = myString[:i] + myString[i:]
            myString = newString
    return myString

def fixCapitalization(myString):
    temp1 = myString
    temp2 = removeWhiteSpace(temp1)
    numberOfFixes = 0;
    newString = ""

    return [numberOfFixes, newString]
    
myString = "hello woRRld."
