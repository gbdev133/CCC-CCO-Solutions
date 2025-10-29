import sys
input = sys.stdin.readline

n = int(input())
a = [0] * (n + 1)
ways = [1] * (n + 1)
for i in range(1, n):
    a[i] = int(input())
    ways[i] += 1
    ways[a[i]] *= ways[i]
print(ways[n])