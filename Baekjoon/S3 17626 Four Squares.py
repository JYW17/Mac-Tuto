import sys
input = sys.stdin.readline

n = int(input().rstrip())

lis = [0 for i in range(n+1)]
lis[0] = 0
lis[1] = 1

for i in range(2, n+1):
    
    minValue = 4
    j = 1
    
    while j**2 <= i:
        minValue = min(lis[i-j**2], minValue)
        j += 1
    
    lis[i] = minValue+1

print(lis[n])