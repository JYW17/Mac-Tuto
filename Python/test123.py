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



# n = int(input())
# fac = 1
# for i in range(1,n+1):
#     fac *= i
# print(fac)

# cnt = 0

# for i in reversed(str(fac)):
#     if i == "0":
#         cnt += 1
#     else:
#         break
# print(cnt)

# n, m, s = map(int, input().split())

# lis = [[0] * (n)] * (m)

# print(lis)

# i, j = 0, 0
# val = 1
# current_state = 0

# if s == 0:
#     current_state = 0
        
#     while val <= n * m:
#         if lis[i][j] == 0:
#             lis[i][j] = val
#             val += 1

#         # 행,열 증가 이후에는 행,열 감소를 해야함
#         # 이후 다시 행열 증가를 해야함
#         # state 0 -> 1 -> 2 -> 3 -> 0
#         # 0: i 증가
#         # 1: j 증가
#         # 2: i 감소
#         # 3: j 감소
#         if current_state == 0:
#             i += 1
#             if i >= m or lis[i][j] != 0:
#                 i -= 1
#                 current_state = 1
        
#         if current_state == 1:
#             j += 1
#             if j == n or lis[i][j] != 0:
#                 j -= 1
#                 current_state = 2
        
#         if current_state == 2:
#             i -= 1
#             if i < 0 or lis[i][j] != 0:
#                 i += 1
#                 current_state = 3
        
#         if current_state == 3:
#             j -= 1
#             if j < 0 or lis[i][j] != 0:
#                 j += 1
#                 i += 1
#                 current_state = 0

# print("rst:", end=" ")
# for i in range(m):
#     for j in range(n):
#         print(lis[i][j], end=" ")
#     print()

n = int(input())
m = []
for i in range(1, n//2+1):
   if i not in m and n % i == 0:
      m.append(i)
      m.append(n//i)
m.sort()

temp = []
for i in range(len(m)//2):
   for j in range(i, len(m)):
      for k in range(j, len(m)):
         if m[i]*m[j]*m[k] == n and [m[i], m[j], m[k]] not in temp:
            temp.append([m[i], m[j], m[k]])

for i in range(len(temp)):
   print(temp[i][0], '*', temp[i][1], '*', temp[i][2], '=', temp[i][0]*temp[i][1]*temp[i][2])

