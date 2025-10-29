import sys
input = sys.stdin.readline

l = int(input())
for i in range(l):
    t = list(input().strip())
    temp = t[0]
    ans = 1
    for x in range(1, len(t)):
        if temp != t[x]:
            print(f"{ans} {temp} ", end="")
            ans = 1
            temp = t[x]
        else:
            ans += 1
    print(f"{ans} {t[-1]} ")