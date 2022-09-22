def search(start, end, arr, n):
    if end - start <= 1:
        return start
    
    rst = 0
    mid = (start + end) // 2
    
    for i in arr:
        rst += i//mid
    
    if rst < n:
        return search(start, mid, arr, n)
    elif rst >= n:
        return search(mid, end, arr, n)

k, n = map(int,input().split())

arr = []
big = 0
for i in range(k):
    x = int(input())
    arr.append(x)
    big = max(big, x)

print(search(1, big+1, arr, n))