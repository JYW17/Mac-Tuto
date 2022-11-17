import sys
input = sys.stdin.readline

white = 0
blue = 0


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
    global white, blue
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
                white += 1
            elif temp == 1:
                blue += 1
            else:
                divideAndConquer(i)
        return 
    

if __name__ == "__main__":
    n = int(input().rstrip())
    
    arr = []
    for i in range(n):
        temp = list(map(int,input().split()))
        arr.append(temp)
    
    if judge(arr) == 0:
        white += 1
    elif judge(arr) == 1:
        blue += 1
    else:
        divideAndConquer(arr)
    
    print(white)
    print(blue)
    