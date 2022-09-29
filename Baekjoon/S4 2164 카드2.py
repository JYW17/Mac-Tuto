from collections import deque
import sys

input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    dq = deque([i for i in range(1, n+1)])
    
    while len(dq) > 1:
        dq.popleft()
        dq.append(dq.popleft())
    
    print(dq[0])