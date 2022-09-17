def find(list, n, m):
    result = 0
    
    for i in range(n):
        for j in range(m):
            for k in range(min(m-j,n-i)):
                if(list[i][j] == list[i+k][j] == list[i][j+k] == list[i+k][j+k]) and (result <= k+1):
                    result = k+1
    print(result**2)

n, m = map(int,input().split())

list = list()
for i in range(n):
    list.append(input())

find(list, n, m)