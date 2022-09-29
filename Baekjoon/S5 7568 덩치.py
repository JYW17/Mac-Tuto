n = int(input())
lis = []
for i in range(n):
    lis.append(list(map(int,input().split())))

for i in lis:
    rank = 1
    for j in lis:
        if i[0] < j[0] and i[1] < j[1]:
            rank -= 1
    print(rank, end=" ")
