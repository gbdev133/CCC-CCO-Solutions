vowels = ["a", "e", "i", "o", "u", "y"]
while True:
    s = input()
    if s[-2:] == "or" and len(s) >= 4:
        if s[-3] not in vowels:
            print(s[0:-2] + "our")
        else:
            print(s)
    elif s == "quit!":
        break
    else:
        print(s)