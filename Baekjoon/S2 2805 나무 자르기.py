import sys
sys.setrecursionlimit(10**6)

def sol(start, end, lis, m):
    if end - start <= 1:
        return start
    
    mid = (start+end)//2
    rst = 0
    for i in lis:
        if i >= mid:
            rst += i - mid
    
    if rst >= m:
        return sol(mid, end, lis, m)
    else:
        return sol(start, mid, lis, m)


n,m = map(int,input().split())
lis = list(map(int,input().split()))

start = 0
end = max(lis)

print(sol(start, end, lis, m))