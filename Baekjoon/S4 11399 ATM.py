import sys
input = sys.stdin.readline

n = int(input().rstrip())
lis = list(map(int,input().split()))

lis.sort()
result = 0
for i in range(len(lis)):
    result += sum(lis[0:i+1])
print(result)