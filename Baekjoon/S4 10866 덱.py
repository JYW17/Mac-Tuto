from collections import deque
import sys

input = sys.stdin.readline

n = int(input())
lis = deque()

for i in range(n):
    x = input().split()
    
    if x[0] == "push_front":
        lis.appendleft(int(x[1]))
        continue
    
    if x[0] == "push_back":
        lis.append(int(x[1]))
        continue
    
    if x[0] == "pop_front":
        if not lis:
            print(-1)
        else:
            print(lis.popleft())
        continue
    
    if x[0] == "pop_back":
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
    
    if x[0] == "front":
        if not lis:
            print(-1)
        else:
            print(lis[0])
        continue
    
    if x[0] == "back":
        if not lis:
            print(-1)
        else:
            print(lis[-1])
        continue