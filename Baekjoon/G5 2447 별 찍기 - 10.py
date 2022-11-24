import sys
input = sys.stdin.readline

def checkFalse(arr, row, col, length_3):
    
    for i in range(row+length_3, row+2*length_3):
        for j in range(col+length_3, col+2*length_3):
            arr[i][j] = ' '



n = int(input())
arr = [['*']*n]*n

while n >= 3:
    length_3 = n//3
    
    for i in range(3):
        for j in range(3):
            row = i*length_3
            col = j*length_3
            checkFalse(arr, row, col, length_3//3)
    
    n = n//3

for i in arr:
    print(i)

