poly = input()
rst = ""
for i in poly:
    if i == "x":
        break
    else:
        rst += i
print(int(rst))