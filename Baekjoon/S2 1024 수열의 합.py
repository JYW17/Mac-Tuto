import math

def sum(num, len):
    return (num+num+len-1)*len/2

def printResult(num, len):
    for i in range(len):
        print(num + i, end=" ")

n, l = map(int,input().split())

for i in range(l, 100):
    if sum(math.trunc(n/l), i) == n:
        printResult(math.trunc(n/l),l)
    elif sum(math.trunc(n/l), i) + l == n:
        printResult(math.trunc(n/l)+1,l)
    else:
        continue
