import sys

input = sys.stdin.readline

n = int(input())
lis = []
for i in range(n):
    x = input().split()
    if x[0] == "push":
        lis.append(int(x[1]))
        continue
    
    if x[0] == "pop":
        if not lis:
            print(-1)
        else:
            print(lis.pop())
        continue
    
    if x[0] == "size":
        print(len(lis))
        continue
    
    if x[0] == "empty":
        if not lis:
            print(1)
        else:
            print(0)
        continue
    
    if x[0] == "top":
        if not lis:
            print(-1)
        else:
            print(lis[-1])
        continue
