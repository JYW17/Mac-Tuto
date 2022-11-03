import sys
input = sys.stdin.readline

def dps(link, stk, visited, connectedNodes):
    pass


n,m = map(int, input().split())

connectedNodes = [0 for i in range(n)]
link = []
stk = []
visited = [False for i in range(n+1)]

for i in range(m):
    link.append(list(map(int, input().split())))

for i in link:
    dps(i, stk, visited, connectedNodes)