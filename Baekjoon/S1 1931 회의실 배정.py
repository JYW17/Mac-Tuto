import sys
input = sys.stdin.readline

# def findMin(timeTable, start):
#     cnt = 1
#     temp = start[1]
    
#     for i in timeTable:
#         if temp <= i[0]:
#             temp = i[1]
#             cnt += 1
#         else:
#             continue
    
#     return cnt

if __name__ == "__main__":
    n = int(input().rstrip())
    
    timeTable = [[0]*2 for i in range(n)]
    resultList = [0] * n
    for i in range(n):
        timeTable[i][0], timeTable[i][1] = map(int, input().split())
    
    timeTable.sort(key = lambda x: (x[1], x[0]))
    print(timeTable)
    
    cnt = 0
    end = 0
    for i in timeTable:
        if i[0] >= end:
            cnt += 1
            end = i[1]
    
    print(cnt)