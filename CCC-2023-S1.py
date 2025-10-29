import sys
input = sys.stdin.readline

c = int(input())
r1 = list(map(int, input().split()))
r2 = list(map(int, input().split()))

ans = 0
for i in range(c):
    if r1[i]:
        cnt = 3
        if i != 0 and r1[i-1]:
            cnt -= 1
        if i < c-1 and r1[i+1]:
            cnt -= 1
        if i % 2 == 0 and r2[i]:
            cnt -= 1
        ans += cnt

for i in range(c):
    if r2[i]:
        cnt = 3
        if i != 0 and r2[i-1]:
            cnt -= 1
        if i < c-1 and r2[i+1]:
            cnt -= 1
        if i % 2 == 0 and r1[i]:
            cnt -= 1
        ans += cnt
print(ans)