import sys
import re
input = sys.stdin.readline

s, t = input().strip(), input().strip()
s = re.sub("[^A-Z]", "", s)
t = re.sub("[^A-Z]", "", t)
idx = 0
i = 0
a = [ord(x) - ord("A") for x in s]
ans = ""
while idx < len(t):
    if i == len(a):
        i = 0

    if ord(t[idx]) + a[i] > ord("Z"):
        ans += chr(ord(t[idx]) + a[i] - 26)
    else:
        ans += chr(ord(t[idx]) + a[i])
    idx += 1
    i += 1
print(ans)