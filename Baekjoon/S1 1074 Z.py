import sys
input = sys.stdin.readline


n,r,c = map(int,input().split())

start = 0

while n >= 1:
    n -= 1
    
    if r < 2**n and c < 2**n:
        start += 0
    elif r < 2**n and c >= 2**n:
        start += 1*(2**n)**2
        c -= 2**n
    elif r >= 2**n and c < 2**n:
        start += 2*(2**n)**2
        r -= 2**n
    elif r >= 2**n and c >= 2**n:
        start += 3*(2**n)**2
        r -= 2**n
        c -= 2**n


print(start)
