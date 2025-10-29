def addRow(row, add):
    i = 0
    while add != 0:
        row[i] = "*"
        row[len(row) - 1 - i] = "*"
        add -= 2
        i += 1


height = int(input())
tie = [[" "] * (2 * (height - 2) + 4) for i in range(height)]

add = 2
for i in range(len(tie)):
    addRow(tie[i], add)
    if i < height // 2:
        add += 4
    else:
        add -= 4

for x in tie:
    for y in x:
        print(y, end="")
    print()