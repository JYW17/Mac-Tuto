# import sys
# input = sys.stdin.readline

# l = int(input())
# if l != 0:
#     x = input()
# rst = 0

# for i in range(l):
#     rst += (ord(x[i])-96)*(31**i)
# print(rst)
lis = [1,2,3,4,5]
rst = 0
for i in range(len(lis)):
    rst += sum(lis[0:i+1])
    print(rst)
print(rst)
