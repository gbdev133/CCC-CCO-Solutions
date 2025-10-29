import sys
input = sys.stdin.readline

d = {1: 100, 2: 500, 3: 1000, 4: 5000, 5: 10000, 6: 25000, 7: 50000, 8: 100000, 9: 500000, 10: 1000000}
x = 1691600
n = int(input())
for i in range(n):
    x -= d[int(input())]

print("deal" if int(input()) > x / (10 - n) else "no deal")
