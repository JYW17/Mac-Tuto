num = int(input())
result = num
for i in range(num+1,0,-1):
    sum = 0
    for j in str(i):
        sum += int(j)
    if num == i + sum and result > i:
        result = i
if result != num:
    print(0)
else:
    print(result)