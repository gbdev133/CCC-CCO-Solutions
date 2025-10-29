import sys
input = sys.stdin.readline
s = input().strip()
d = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

ans = 0
for i in range(0, len(s) - 3, 2):
    if d[s[i + 1]] < d[s[i + 3]]:
        ans -= int(s[i]) * d[s[i + 1]]
    else:
        ans += int(s[i]) * d[s[i + 1]]

print(ans + int(s[-2]) * d[s[-1]])