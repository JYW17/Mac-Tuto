lis0 = ["WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"]
lis1 = ["BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"]

n,m = map(int,input().split())
board = list()

for i in range(n):
    board.append(input())

minCount0 = 64
minCount1 = 64
result = 64

for i in range(n-7):
    for j in range(m-7):
        count0 = 0
        count1 = 0
        for a in range(8):
            for b in range(8):
                if (board[i+a][j+b] != lis0[a][b]):
                    count0 += 1
                if (board[i+a][j+b] != lis1[a][b]):
                    count1 += 1
        if (result > min(count0, count1)):
            result = min(count0, count1)

print(result)
