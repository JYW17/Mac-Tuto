# 다이나믹 프로그래밍에서 중요한 것은 점화식을 세우는 것이다
# 그러니 점화식을 세울 때 앞에서도 생각하고 뒤에서도 생각해서 
# 올바른 점화식을 찾아보자

import sys
input = sys.stdin.readline

def judge3(k):
    if k % 3 == 0:
        return int(k/3)
    else:
        return k-1

def judge2(k):
    if k % 2 == 0:
        return int(k/2)
    else:
        return k-1

lis = [0,0,1,1,2,3,2] # 1부터 6까지의 최소 연산 수

n = int(input())

if n >= 7:
    for i in range(7, n+1):
        lis.append(1+min(lis[judge3(i)], lis[judge2(i)], lis[i-1]))

print(lis[n])