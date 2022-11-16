import sys
from collections import deque
input = sys.stdin.readline

def bfs(graph, start):
    visited = []
    
    que = deque()
    que.append(start)
    
    while que:
        curr = que.pop()
        
        if curr in visited:
            continue
        
        visited.append(curr)
        que.extend(graph[curr])
    visited.remove(1)
    print(visited)
    
    return len(visited)

if __name__ == "__main__":
    num = int(input().rstrip())
    linkNum = int(input().rstrip())
    link = []
    
    graph = [[] for i in range(num+1)]
    
    # 링크을 입력 받음
    for i in range(linkNum):
        link.append(list(map(int, input().split())))
    
    # 링크를 토대로 그래프 작성
    for i in link:
        graph[i[0]].append(i[1])
        graph[i[1]].append(i[0])
    
    print(bfs(graph, 1))
    