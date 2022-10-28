# import sys
# input = sys.stdin.readline

# l = int(input())
# if l != 0:
#     x = input()
# rst = 0

# for i in range(l):
#     rst += (ord(x[i])-96)*(31**i)
# print(rst)
<<<<<<< HEAD
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
=======
dic = {'eye':1, 'face':2, 'shoes': 3}
lis = []
for i in dic:
    lis.append(dic[i])
print(lis)
>>>>>>> d31087db513691e66cfeedb01884471d5e823614
