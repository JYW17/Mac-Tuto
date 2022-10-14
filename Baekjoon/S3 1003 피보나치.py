fibList = list()
fibList.append([1,0])
fibList.append([0,1])

for n in range(2, 41):
    fibList.insert(n, [fibList[n-1][0] + fibList[n-2][0], fibList[n-1][1] + fibList[n-2][1]]) 


t = int(input())
for i in range(t):
    num = int(input())
    print(fibList[num][0], fibList[num][1])
