n, m = map(int,input().split())

pack_price = list()
indivi1 = list()

for i in range(m):
    a, b = map(int,input().split())
    pack_price.append(a)
    indivi1.append(b)

min_pack = min(pack_price)
min_indi = min(indivi1)
sum = 0

if min_pack < 6*min_indi:

    if min_pack < (n%6)*min_indi:
        sum += min_pack*(n//6 + 1)
    else:
        sum += min_pack*(n//6)
        sum += min_indi*(n%6)
else:
    sum += n*min_indi

print(sum)