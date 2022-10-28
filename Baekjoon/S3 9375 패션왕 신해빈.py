import sys
input = sys.stdin.readline

case = int(input().rstrip())

for i in range(case):
    n = int(input().rstrip())
    dic = {}
    for i in range(n):
        sen, category = input().split()
        if category in dic:
            dic[category] += 1
        else:
            dic[category] = 1
    lis = []
    for i in dic:
        lis.append(dic[i])
    rst = 1
    for i in lis:
        rst *= i+1
    print(rst-1)