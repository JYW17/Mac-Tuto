from collections import Counter
import sys

input = sys.stdin.readline

n = int(input())
lis = []

for i in range(n):
    x = int(input())
    lis.append(x)

#산술평균
print(round(sum(lis) / n))
#중앙값
lis.sort()
print(lis[int(n/2)])
#최빈값
counterLis = Counter(lis).most_common(2)

if len(counterLis) > 1:
    if counterLis[0][1] == counterLis [1][1]:
        print(counterLis[1][0])
    else:
        print(counterLis[0][0])
else:
    print(counterLis[0][0])
#범위
print(lis[-1]-lis[0])