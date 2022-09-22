from sys import stdin, stdout
input = stdin.readline
print = stdout.write

n = int(input())
lis1 = list(input().split())
m = int(input())
lis2 = list(input().split())

for i in lis2:
    if i in lis1:
        print("1\n")
    else:
        print("0\n")
