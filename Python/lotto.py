# import sys
# input = sys.stdin.readline

# l = int(input())
# if l != 0:
#     x = input()
# rst = 0

# for i in range(l):
#     rst += (ord(x[i])-96)*(31**i)
# print(rst)

# k, l = map(int,input().split())
# rst = 0
# for i in range(2, l):
#     if k % i == 0 and i < l:
#         temp = False
#         rst = i
#         break

import random

def yengum(n):
        
    print(random.randint(1,5), end=": ")
    for i in range(6):
        print(random.randint(1,10), end=" ")
    print()

def lotto(n):
    
    for i in range(n):    
        
        visited = []
        while True:
            x = random.randint(1,45)
            while x not in visited:
                visited.append(x)
            if len(visited) >= 6:
                break

        visited.sort()
        print('이번의 로또!!', end='')
        for i in visited:
            print(i, end=' ')
        print()
    
if __name__ == '__main__':
    lotto(5)