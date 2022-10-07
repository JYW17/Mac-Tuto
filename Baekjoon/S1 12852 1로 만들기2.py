# 다이나믹 프로그래밍에서 중요한 것은 점화식을 세우는 것이다
# 그러니 점화식을 세울 때 앞에서도 생각하고 뒤에서도 생각해서 
# 올바른 점화식을 찾아보자

from re import sub
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
# dic = {0:0, 1:0, 2:1, 3:1, 4:2, 5:3, 6:2}
stk = [[0],[1],[2,1], [3,1], [4, 3, 1], [5, 4, 3, 1], [6, 3, 1]]

n = int(input())

if n >= 7:
    for i in range(7, n+1):
        # print("{}번째 사이클".format(i))
        div3 = judge3(i)
        div2 = judge2(i)
        sub1 = i - 1
        index = 0
        x = min(lis[div3], lis[div2], lis[sub1])
        if lis[div3] == x:
            index = div3
        elif lis[div2] == x:
            index = div2
        else:
            index = sub1
        # print("index =", index)
        # dic[i] = 1 + x
        lis.append(1 + x)
        # print("lis = ", lis)
        temp = [i]
        temp.extend(stk[index])
        # print("temp =", temp)
        stk.append(temp)
        # print("stk =", stk)
        # print()

print(lis[n])

for i in stk[n]:
    print(i, end=" ")