import sys
input = sys.stdin.readline

cntMinus1 = 0
cnt0 = 0
cnt1 = 0 

def judge(arr):
    set0 = set()
    
    for i in arr:
        # if i == -1:
        #     set0.add(i)
        # elif i == 0:
        #     set0.add(i)
        # elif i == 1:
        #     set0.add(i)
        # else:
        #     
        set0.update(i)
    
    if len(set0) == 1:
        return True
    else:
        return False

def sliceAndCount(arr):
    col = len(arr)
    index = int(col/3)
    global cntMinus1, cnt0, cnt1
    if col > 1:
        arr1 = []
        for i in range(index):
            arr1.append(arr[i][:index])

        arr2 = []
        for i in range(index):
            arr2.append(arr[i][(index):2*(index)])

        arr3 = []
        for i in range(index):
            arr3.append(arr[i][2*(index):3*(index)])

        arr4 = []
        for i in range((index), 2*(index)):
            arr4.append(arr[i][:index])

        arr5 = []
        for i in range((index), 2*(index)):
            arr5.append(arr[i][(index):2*(index)])

        arr6 = []
        for i in range((index), 2*(index)):
            arr6.append(arr[i][2*(index):3*(index)])

        arr7 = []
        for i in range(2*(index), 3*(index)):
            arr7.append(arr[i][:index])

        arr8 = []
        for i in range(2*(index), 3*(index)):
            arr8.append(arr[i][(index):2*(index)])

        arr9 = []
        for i in range(2*(index), 3*(index)):
            arr9.append(arr[i][2*(index):3*(index)])
        
        rst = [arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9]
        
        for i in rst:
            if judge(i):
                if i[0][0] == -1:
                    cntMinus1 += 1
                elif i[0][0] == 0:
                    cnt0 += 1
                elif i[0][0] == 1:
                    cnt1 += 1
            else:
                sliceAndCount(i)
        return 



n = int(input())
arr = [[] for i in range(n)]
for i in range(n):
    lis = list(map(int,input().split()))
    arr[i] = lis

# test = sliceArr(arr)
# for i in test:
#     print(i)
# print("judge1", judge([[1]]))
# print("judge2", judge(test))
if judge(arr):
    if arr[0][0] == -1:
        cntMinus1 += 1
    if arr[0][0] == 0:
        cnt0 += 1
    if arr[0][0] == 1:
        cnt1 += 1
else:
    sliceAndCount(arr)

print(cntMinus1)
print(cnt0)
print(cnt1)