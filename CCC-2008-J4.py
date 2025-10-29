import sys
input = sys.stdin.readline
x = input().strip().split()
while x != ["0"]:
    s = []
    for i in range(len(x) - 1, -1, -1):
        try:
            s.append(int(x[i]))
        except:
            op1 = str(s.pop())
            op2 = str(s.pop())
            v = op1 + " " + op2 + " "
            v += "+" if x[i] == "+" else "-"
            s.append(v)
    for k in s:
        print(k, end=" ")
    print("\n", end="")
    x = input().strip().split()