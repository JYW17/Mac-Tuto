import math

def yCharge(list):
    result = 0
    for i in list:
        if i//30 > 0 and i%30 == 0:
            result += (10*math.ceil(i/30) + 10)
        else:
            result += 10*math.ceil(i/30)
    return result

def mCharge(list):
    result = 0
    for i in list:
        if i//60 > 0 and i%60 == 0:
            result += (15*math.ceil(i/60) + 15)
        else:
            result += 15*math.ceil(i/60)
    return result

num = int(input())
nums = input()
list = list()
for i in nums.split():
    list.append(int(i))

if yCharge(list) == mCharge(list):
    print("Y M", yCharge(list))
elif yCharge(list) < mCharge(list):
    print("Y", yCharge(list))
else:
    print("M", mCharge(list))