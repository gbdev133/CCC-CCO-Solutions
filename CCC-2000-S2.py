import sys
input = sys.stdin.readline

n = int(input())
a = [0] * n
for i in range(n):
    a[i] = int(input())
cmd, idx = int(input()), int(input()) - 1
while True:
    if cmd == 99:
        flow = int(input())
        a.insert(idx, round(a[idx] * (flow / 100)))
        a[idx + 1] = round(a[idx + 1] * (100 - flow) / 100)
    else:
        a[idx] += a.pop(idx + 1)
    cmd = int(input())
    if cmd == 77:
        break
    idx = int(input()) - 1
for x in a:
    print(x, end=" ")