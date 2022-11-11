from collections import deque
import sys
input = sys.stdin.readline

def bfs(distance, n, k):
    que = deque()
    que.append(n)
    
    while que:
        curr = que.popleft()
        if curr == k:
            break
        for i in (curr+1, curr-1, curr*2):
            if 0<= i <= MAX and not distance[i]:
                distance[i] = distance[curr] + 1
                que.append(i)


if __name__ == "__main__":
    n,k = map(int,input().split())
    MAX = 10**6
    distance = [0] * (MAX+1)
    bfs(distance= distance, n=n, k=k)
    print(distance[k]) 