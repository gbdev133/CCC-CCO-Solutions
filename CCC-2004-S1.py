import sys

input = sys.stdin.readline

N = int(input())

for i in range(N):
    arr = []
    good = True
    for j in range(3):
        arr.append(input().strip())
    if (arr[0].startswith(arr[1]) or arr[1].startswith(arr[0]) or
            arr[0].endswith(arr[1]) or arr[1].endswith(arr[0])):
        good = False
    elif (arr[2].startswith(arr[1]) or arr[1].startswith(arr[2]) or
            arr[2].endswith(arr[1]) or arr[2].endswith(arr[1])):
        good = False
    elif (arr[2].startswith(arr[0]) or arr[0].startswith(arr[2]) or
            arr[2].endswith(arr[0]) or arr[2].endswith(arr[0])):
        good = False

    print("Yes" if good else "No")