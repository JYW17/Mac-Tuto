list = []
list.append(1)
list.append(1)
list.append(3)

for i in range(3, 300):
    list.append(list[i-1] + 2*list[i-2])



while True:
    try:
        num = int(input())
        print(list[num])
    except:
        break
