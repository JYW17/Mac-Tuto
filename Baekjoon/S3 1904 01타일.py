import sys
# num = int(input())

# a = 1
# b = 2

# for i in range(2, num):
#     tp = b
#     b = a+b
#     a = tp
#     print(b)
num = int(input())

list = [0 for i in range(1000000)]
list[0] = 1
list[1] = 2

for i in range(2, num):
    list[i] = (list[i-1] + list[i-2])%15746

print(sys.getsizeof(list))
print(list[num-1])