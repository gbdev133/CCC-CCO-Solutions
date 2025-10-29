import sys

input = sys.stdin.readline

letters = {}
letters2 = {}
s = input().strip()
s2 = input().strip()
for c in s:
    if c != " ":
        if c not in letters:
            letters[c] = 1
        else:
            letters[c] += 1

for c in s2:
    if c != " ":
        if c not in letters2:
            letters2[c] = 1
        else:
            letters2[c] += 1

good = True
for x in letters.keys():
    if x not in letters2 or letters[x] != letters2[x]:
        good = False
        break
print("Is an anagram." if good else "Is not an anagram.")
