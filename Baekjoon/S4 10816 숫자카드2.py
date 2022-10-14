import sys
from collections import Counter

input = sys.stdin.readline

n = int(input())
lis1 = list(map(int,input().split()))
m = int(input())
lis2 = list(map(int,input().split()))

ans = Counter(lis1)

for i in lis2:
    print(ans[i], end=" ")