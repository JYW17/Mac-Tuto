import sys
from xml.dom.expatbuilder import InternalSubsetExtractor
input = sys.stdin.readline

n,m,b = map(int,input().split())
lis = []
for i in range(n):
    lis.append(list(map(int,input().split())))

ansTime = sys.maxsize
ansFloor = 257

for floor in range(0,257):
    outBlock, inBlock = 0,0
    
    for i in lis:
        for j in i:
            if floor - j > 0: #블록을 쌓음
                outBlock += (floor-j)
            else:
                inBlock += (j - floor)
                
    if inBlock + b >= outBlock:
        if 2*inBlock + outBlock <= ansTime:
            ansTime = (2*inBlock + outBlock)
            ansFloor = floor

print(ansTime, ansFloor)