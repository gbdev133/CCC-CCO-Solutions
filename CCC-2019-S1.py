import sys
input = sys.stdin.readline


s = input().strip()
a = [1, 2, 3, 4]
cmd = ""


h = s.count("H")
v = s.count("V")
if h % 2 != 0:
    cmd = "H"
if v % 2 != 0:
    cmd += "V"
for x in cmd:
    if x == "H":
        temp1, temp2 = a[0], a[1]
        a[0], a[1] = a[2], a[3]
        a[2], a[3] = temp1, temp2
    else:
        temp1, temp2 = a[0], a[2]
        a[0], a[2] = a[1], a[3]
        a[1], a[3] = temp1, temp2

print(a[0], a[1])
print(a[2], a[3])