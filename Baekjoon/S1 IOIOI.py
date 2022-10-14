import sys
input = sys.stdin.readline

n = int(input().rstrip())
lens = int(input().rstrip())
s = input().rstrip()

check = "I"
for i in range(n):
    check += "OI"

cnt = 0
i = 0
pattern = 0

while i < lens - 2:
    if s[i] == "I" and s[i+1] == "O" and s[i+2] == "I":
        pattern += 1
        if pattern == n:
            pattern -= 1
            cnt += 1
        i += 2
    else:
        pattern = 0
        i += 1

print(cnt)