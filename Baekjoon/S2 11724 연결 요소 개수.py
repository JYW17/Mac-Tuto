from collections import deque
import sys

input = sys.stdin.readline

def dfs(graph, startNode, visitedNodes):
    stk = deque()
    stk.append(startNode)
    
    while stk:
        curr = stk.pop()
        
        if not visitedNodes[curr]:
            visitedNodes[curr] = True
            stk.extend(graph[curr])


if __name__ == "__main__":
    n,m = map(int,input().split())
    graph = [[] for i in range(n+1)] # 그래프 생성
    visitedNodes = [False for i in range(n+1)] # 방문 여부 확인 리스트
    
    # 링크를 토대로 그래프 작성
    for i in range(m):
        a,b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    
    rst = 0
    for i in range(1, n+1):
        if not visitedNodes[i]:
            rst += 1
            dfs(graph=graph, startNode=i, visitedNodes=visitedNodes)
    print(rst)