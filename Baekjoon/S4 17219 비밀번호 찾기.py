import sys
input = sys.stdin.readline

n,m = map(int, input().split())

memo = dict()

for i in range(n):
    site, password = map(str, input().split())
    memo[site] = password

for i in range(m):
    print(memo[input().rstrip()])
