from collections import deque
import sys
input = sys.stdin.readline

n,m = map(int,input().split())
findArr = list(map(int,input().split()))

dq = deque([i for i in range(1, n+1)])

rst = 0

for i in findArr:
    indexDistance = 0
    while True:
        if dq[0] == i:
            dq.popleft()
            break
        else:
            while dq[0] != i:
                dq.append(dq.popleft())
                indexDistance += 1
            
            rst += min(len(dq) - indexDistance, indexDistance)

print(rst)