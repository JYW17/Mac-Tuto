n = int(input())
lis = list()
for i in range(n):
    lis.append(int(input()))

stack = []
output = []
cur = 1
temp = True

for i in range(n):
    
    while cur <= lis[i]:
        output.append("+")
        stack.append(cur)
        cur += 1
    
    if stack[-1] == lis[i]:
        output.append("-")
        stack.pop()
    else:
        temp = False
        break

if temp == False:
    print("NO")
else:
    for i in output:
        print(i)