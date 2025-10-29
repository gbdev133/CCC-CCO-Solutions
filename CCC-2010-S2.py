import sys
input = sys.stdin.readline

chars = {}
k = int(input())
for _ in range(k):
    s = input().split()
    chars.update({s[1]: s[0]})

c = input().strip()
ans, char = "", ""
while len(c) > 0:
    for x in chars.keys():
        if c.startswith(x):
            ans += chars[x]
            c = c[len(x):]
            break


print(ans)
