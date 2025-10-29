import sys
input = sys.stdin.readline
b, n = 0, 0
songs = ["A", "B", "C", "D", "E"]
while b != 4:
    b = int(input())
    n = int(input())
    for i in range(n):
        if b == 1:
            songs.append(songs[0])
            songs.pop(0)
        elif b == 2:
            songs.insert(0, songs.pop())
        elif b == 3:
            songs.insert(2, songs[0])
            songs.pop(0)

for x in songs:
    print(x, end=" ")