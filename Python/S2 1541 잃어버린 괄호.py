import sys
input = sys.stdin.readline

poly = input()

pol = []
add = []
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

