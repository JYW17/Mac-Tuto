# num = int(input())
# lis = list()
# a = input().split()
# for i in a:
#     lis.append(int(i))

# lis.sort()
# print(lis[0], lis[-1])
# a, num = map(int,input().split())
# b = input().split()
# for i in b:
#     if int(i) < num:
#         print(int(i), end=" ")
# num = int(input())
# result = num
# for i in range(num+1,0,-1):
#     sum = 0
#     for j in str(i):
#         sum += int(j)
#     if num == i + sum and result > i:
#         result = i
# if result == num:
#     print(0)
# else:
#     print(result)
from collections import Counter
import math

n = int(input())
lis = []

for i in range(n):
    x = int(input())
    lis.append(x)

counterLis = Counter(lis).most_common(2)
print(counterLis)
counterLis.sort()
print(counterLis)
