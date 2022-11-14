import sys
from collections import deque

input = sys.stdin.readline

def bfs(graph):
    cnt = 0
    que = deque()    
    que.append([0,0])
    
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    
    destination = [len(graph) - 1, len(graph[0]) - 1]
    
    while que:
        poped = que.popleft()
        
        if poped == [n-1, m-1]:
            break
        
        y, x = poped[0], poped[1]
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx <= m-1 and 0 <= ny <= n-1 and graph[ny][nx] == 1:
                graph[ny][nx] = graph[y][x] + 1
                que.append([ny, nx])
        
    
    return graph[n-1][m-1]

if __name__ == "__main__":
    n,m = map(int, input().split())
    graph = []
    
    for i in range(n):
        graph.append(list(map(int,list(input().rstrip()))))
    
    print(bfs(graph))