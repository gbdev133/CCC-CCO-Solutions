import sys

input = sys.stdin.readline

a, b = input().strip(), input().strip()
arr = [set() for _ in range(5)]

for i in range(0, 10, 2):
    for j in range(2):
        for k in range(2):
            arr[i // 2].add("".join(sorted(a[i + j] + b[i + k])))

for _ in range(int(input())):
    good = True
    s = input().strip()
    for j in range(5):
        if s[j] == s[j].lower():
            if s[j] * 2 not in arr[j]:
                print("Not their baby!")
                break
        else:
            if s[j] + s[j].lower() not in arr[j] and s[j] * 2 not in arr[j]:
                print("Not their baby!")
                break
    else:
        print("Possible baby.")
