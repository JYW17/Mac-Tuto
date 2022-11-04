from collections import deque
import sys
input = sys.stdin.readline

def bfs(graph, startNode):
    n = len(graph) -1 # 인원 수
    linkCnt = [0 for i in range(n+1)] # startNode의 각 사람들에 대한 케빈 파이기 수들
    visited = [startNode] # 방문한 노드들의 리스트
    que = deque() # 큐
    que.append(startNode) # 큐에 시작 지점 넣기
    
    while que:
        curr = que.popleft()
        
        for closeNode in graph[curr]:
            if closeNode in visited:
                continue
            
            visited.append(closeNode) # 방문한 노드 표시
            que.append(closeNode) # 큐에 인접한 노드 추가
            
            linkCnt[closeNode] = linkCnt[curr] + 1
        
    return sum(linkCnt)



if __name__ == "__main__":
    
    n, m = map(int, input().split())
    graph = [[] for i in range(n+1)]
    
    for i in range(m):
        a, b = map(int,input().split())
        graph[a].append(b)
        graph[b].append(a)
    # print(graph)
    
    rst = [0 for i in range(n)]
    for i in range(n):
        rst[i] = bfs(graph, i+1)
        
    # print(rst)
    print(rst.index(min(rst))+1)