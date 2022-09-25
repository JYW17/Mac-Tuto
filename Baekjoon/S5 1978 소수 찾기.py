import math

arr = [True for i in range(1000 + 1)]
arr[0] = False
arr[1] = False

for i in range(2, int(math.sqrt(1000))+1):
    if arr[i] == True:
        j = 2
        while i*j <= 1000:
            arr[i*j] = False
            j += 1

n = int(input())
lis = list(map(int,input().split()))
count = 0

for i in lis:
    if arr[i] == True:
        count += 1

print(count)
