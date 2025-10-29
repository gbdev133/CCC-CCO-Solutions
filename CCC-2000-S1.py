import sys
input = sys.stdin.readline

quarters = int(input())
a, b, c = int(input()), int(input()), int(input())
plays = 0
while quarters >= 1:
        a += 1
        plays += 1
        quarters -= 1
        if a % 35 == 0 and a != 0:
            quarters += 30
        if quarters == 0:
            break

        b += 1
        quarters -= 1
        plays += 1
        if b % 100 == 0 and b != 0:
            quarters += 60
        if quarters == 0:
            break

        quarters -= 1
        c += 1
        plays += 1
        if c % 10 == 0 and c != 0:
            quarters += 9
        if quarters == 0:
            break


print(f"Martha plays {plays} times before going broke.")
