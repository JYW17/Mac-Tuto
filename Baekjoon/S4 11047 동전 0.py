def findTemp(k, arr):
    temp = arr[0]
    for i in arr:
        if i <= k:
            temp = i
    return temp



import sys
input = sys.stdin.readline

n, k = map(int,input().split())
lis = []

for i in range(n):
    lis.append(int(input().rstrip()))

money = k
cnt = 0
while money > 0:
    
    temp = findTemp(money, lis)
    
    cor = (money // temp)
    if cor == 0:
        money -= temp
        cnt += 1
    else:
        money -= cor * temp
        cnt += cor

print(cnt)