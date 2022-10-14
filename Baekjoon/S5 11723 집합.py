# 집합 문제였기에 단순히 집합으로 풀려고 했지만 
# 알고 보니 비트마스킹이었다...
# 그래서 0과 1로 이루어진 리스트로 빠르게 돌아가게 만듦

import sys
input = sys.stdin.readline

m = int(input().rstrip())
s = list(0 for i in range(21))

for i in range(m):
    x = input().split()
    if x[0] == "add":
        if s[int(x[1])] == 1:
            continue
        else:
            s[int(x[1])] = 1
            continue
    elif x[0] == "remove":
        if s[int(x[1])] == 1:
            s[int(x[1])] = 0
            continue
        else:
            continue
    elif x[0] == "check":
        if s[int(x[1])] == 1:
            print(1)
            continue
        else:
            print(0)
            continue
    elif x[0] == "toggle":
        if s[int(x[1])] == 1:
            s[int(x[1])] = 0
            continue
        else:
            s[int(x[1])] = 1
            continue
    elif x[0] == "all":
        s = [1 for i in range(21)]
        continue
    elif x[0] == "empty":
        s = [0 for i in range(21)]
