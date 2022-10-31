# import sys
# input = sys.stdin.readline

# l = int(input())
# if l != 0:
#     x = input()
# rst = 0

# for i in range(l):
#     rst += (ord(x[i])-96)*(31**i)
# print(rst)
import sys
input = sys.stdin.readline

while True:
    sen = list(input().split())
    if sen[0] == '#' and int(sen[1]) == 0 and int(sen[2]) == 0:
        break
    if int(sen[1]) > 17 or int(sen[2]) >= 80:
        print(sen[0], 'Senior')
    else:
        print(sen[0], 'Junior')
