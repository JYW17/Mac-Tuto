import sys
input = sys.stdin.readline

poly = input()

pol = []
add = []
final = []
num = ""

for i in poly:
    if i == "-":
        add.append(int(num))
        num = ""
        pol.append(sum(add))
        add.clear()
    
    elif i == "+":
        add.append(int(num))
        num = ""
    
    else:
        num += i
add.append(int(num))
pol.append(sum(add))

rst = 2*pol[0]
for i in pol:
    rst -= i
print(rst)