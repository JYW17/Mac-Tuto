poly = input()
rst = ""
temp = False
for i in poly:
    if i == "x":
        temp = True
        break
    else:
        rst += i

if poly[0] == "x":
    print(1)
elif poly[0] == "-" and poly[1] == "x":
    print(-1)
elif temp == True:
    print(int(rst))
else:
    print(0)