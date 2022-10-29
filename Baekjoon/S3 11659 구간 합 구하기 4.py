import sys
input = sys.stdin.readline

n, m = map(int, input().split())
lis = list(map(int, input().split()))

samples = [0]
temp = 0
for i in range(n):
    temp += lis[i]
    samples.append(temp)

for i in range(m):
    a,b = map(int, input().split())
    print(samples[b] - samples[a-1])