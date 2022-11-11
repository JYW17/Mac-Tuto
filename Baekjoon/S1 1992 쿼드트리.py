import sys
input = sys.stdin.readline

result = ""

def judge(arr):
    set0 = set()
    
    for i in arr:
        set0.update(i)
    
    if (len(set0) == 1) and (0 in set0):
        return 0
    elif (len(set0) == 1) and (1 in set0):
        return 1
    else:
        return -1

def divideAndConquer(arr):
    global result
    col = len(arr)
    
    index = col//2
    
    if col > 1:
        arr1 = []
        for i in range(index):
            arr1.append(arr[i][:index])

        arr2 = []
        for i in range(index):
            arr2.append(arr[i][index : col])

        arr3 = []
        for i in range(index, col):
            arr3.append(arr[i][:index])

        arr4 = []
        for i in range(index, col):
            arr4.append(arr[i][index : col])
        
        rst = [arr1, arr2, arr3, arr4]
        
        
        for i in rst:
            temp = judge(i)
            if temp == 0:
                result += '0'
            elif temp == 1:
                result += '1'
            else:
                result += '('
                divideAndConquer(i)
                result += ')'
        return 
    

if __name__ == "__main__":
    n = int(input().rstrip())
    
    arr = []
    for i in range(n):
        temp = input().rstrip()
        lis = []
        for i in temp:
            lis.append(int(i))
        arr.append(lis)
    
    if judge(arr) == 1:
        result += '1'
    elif judge(arr) == 0:
        result += '0'
    else:
        result += '('
        divideAndConquer(arr)
        result += ')'
    
    print(result)
    