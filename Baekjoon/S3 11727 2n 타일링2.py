list = []
list.append(1)
list.append(3)

for i in range(2, 1001):
    list.append((list[i-1] + 2*list[i-2])%10007)

num = int(input())
print(list[num-1])