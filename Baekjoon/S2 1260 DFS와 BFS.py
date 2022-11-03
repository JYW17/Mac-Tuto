from collections import deque
import sys
input = sys.stdin.readline

def dfs(graph, v):
    visited = [False for i in range(len(graph))]
    
    stk = deque()
    stk.append(v)
    
    while stk:
        curr = stk.pop()
        
        if visited[curr]:
            continue
        
        visited[curr] = True
        print(curr, end=" ")
        stk.extend(graph[curr])
    


def bfs(graph, v):
    visited = [False for i in range(len(graph))]
    
    que = deque()
    que.append(v)
    
    while que:
        curr = que.popleft()
        
        if visited[curr]:
            continue
        
        visited[curr] = True
        print(curr, end=" ")
        que.extend(reversed(graph[curr]))


if __name__ == "__main__":
    
    n,m,v = map(int, input().split())
    
    link = []
    graph = [[] for i in range(n+1)]
    
    # 링크을 입력 받음
    for i in range(m):
        link.append(list(map(int, input().split())))
    
    # 링크를 토대로 그래프 작성
    for i in link:
        graph[i[0]].append(i[1])
        graph[i[1]].append(i[0])
    
    for i in graph:
        i.sort(reverse=True)
    
    # print(graph)
    
    dfs(graph, v)
    print()
    bfs(graph, v)