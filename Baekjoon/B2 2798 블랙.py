from operator import indexOf


n, m = map(int,input().split())
lis = list(map(int,input().split()))
maxSum = 0

for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            x = lis[i] + lis[j] + lis[k]
            if x > m:
                continue
            else:
                maxSum = max(maxSum, x)

print(maxSum)