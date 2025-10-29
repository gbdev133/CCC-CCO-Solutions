import sys
input = sys.stdin.readline
a = list(map(int, input().split()))
x = 0
b = []
for y in a:
    b.append(x)
    x += y
b.append(x)

for i in range(5):
    for j in range(5):
        print(abs(b[i] - b[j]), end=" ")
    print("\n", end="")