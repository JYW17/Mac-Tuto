from collections import deque
import sys
input = sys.stdin.readline

def bfs(graph, i, j):
    que = deque()    
    que.append([i,j])
    
    n = len(graph)
    m = len(graph[0])
    
    while que:
        poped = que.popleft()
        y, x = poped[0], poped[1]
        
        if graph[y][x] == 0:
            continue
        
        graph[y][x] = 0
        
        if x+1 <= m-1:
            que.append([y, x+1])
        if y+1 <= n-1:
            que.append([y+1, x])
        if x-1 >= 0:
            que.append([y, x-1])
        if y-1 >= 0:
            que.append([y-1, x])
        
    


t = int(input().rstrip())

for i in range(t):
    m,n,k = map(int, input().split())

    graph = [[0 for i in range(m)] for i in range(n)]

    for i in range(k):
        x,y = map(int, input().split())
        graph[y][x] = 1

    cnt = 0
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                continue
            else:
                cnt += 1
                bfs(graph,i,j)
    print(cnt)
