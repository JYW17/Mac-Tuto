from curses.ascii import isdigit
import sys
input = sys.stdin.readline

n,m = map(int,input().split())

dic = {}

for i in range(1, n+1):
    a = input().rstrip()
    dic[i] = a
    dic[a] = i

for i in range(m):
    a = input().rstrip()
    if a.isdigit():
        print(dic[int(a)])
    else:
        print(dic[a])