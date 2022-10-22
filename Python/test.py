# import sys
# input = sys.stdin.readline

# l = int(input())
# if l != 0:
#     x = input()
# rst = 0

# for i in range(l):
#     rst += (ord(x[i])-96)*(31**i)
# print(rst)
# a = 100

# if a == 100:
#     print(11)
# elif a % 2 == 0:
#     print(12)
# else:
#     print(13)


n = input()
if n == "A+":
    print(4.3)
if n == "A0":
    print(4.0)
if n == "A-":
    print(3.7)

if n == "B+":
    print(3.3)
if n == "B0":
    print(3.0)
if n == "B-":
    print(2.7)

if n == "C+":
    print(2.3)
if n == "C0":
    print(2.0)
if n == "C-":
    print(1.7)

if n == "D+":
    print(1.3)
if n == "D0":
    print(1.0)
if n == "D-":
    print(0.7)
    
if n == "F":
    print(0.0)