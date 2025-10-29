import sys
input = sys.stdin.readline
vowels = "aeiou"
n = int(input())
for _ in range(n):
    s = [input().lower().split()[-1] for _ in range(4)]
    for i in range(4):
        for j in range(len(s[i]) - 1, -1, -1):
                if s[i][j] in vowels:
                    s[i] = s[i][j:]
                    break

    if s[0] == s[1] == s[2] == s[3]:
        print("perfect")
    elif s[0] == s[1] and s[2] == s[3]:
        print("even")
    elif s[0] == s[2] and s[1] == s[3]:
        print("cross")
    elif s[0] == s[3] and s[1] == s[2]:
        print("shell")
    else:
        print("free")