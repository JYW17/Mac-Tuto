# def test():
#     return 0


# import sys

# input = sys.stdin.readline

# n = int(input())
# lis = [0] * 10001

# for i in range(n):
#     lis[int(input())] += 1

# for i in range(10001):
#     if lis[i] != 0:
#         for j in range(lis[i]):
#             print(i)

n = int(input())
fac = 1
for i in range(1,n+1):
    fac *= i
print(fac)

cnt = 0

for i in reversed(str(fac)):
    if i == "0":
        cnt += 1
    else:
        break
print(cnt)