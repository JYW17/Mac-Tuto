a, b = input().split()
pointA = 0
pointB = 0
numA = ""
numB = ""

if "." in a:
    for i in reversed(a):
        if i == ".":
            break
        else:
            pointA += 1
print(pointA)
for i in a:
    if i == ".":
        pass
    else:
        numA += i

if "." in b:
    for i in reversed(b):
        if i == ".":
            break
        else:
            pointB += 1
print(pointB)

for i in b:
    if i == ".":
        pass
    else:
        numB += i

if pointA > pointB:
    a = int(numA)
    print(a)
    b = int(numB)*10**(pointA - pointB)
    print(b)
elif pointA < pointB:
    a = int(numA)*10**(pointB - pointA)
    print(a)
    b = int(numB)
    print(b)
else:
    a = int(numA)
    print(a)
    b = int(numB)
    print(b)

rst = str(a+b)
index = -max(pointA, pointB)
if index < 0:
    if abs(index) > len(rst):
        rst = "0."+ "0"*(abs(index)-1) + rst 
    elif abs(index) == len(rst):
        rst = "0." + rst
    else:
        rst = rst[:index] + "." + rst[index:]
else:
    rst = int(rst)
print(rst)