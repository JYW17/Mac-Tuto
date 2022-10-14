FIRST_POSITION = 100

def jump(num, lis):
    ans = 1000000
    
    for i in range(1000001):
        strnum = str(i)
        for j in range(len(strnum)):
            if int(strnum[j]) not in lis:
                break
            elif j == len(strnum)-1:
                ans = min(ans, abs(i - num) + len(strnum))
    return ans

def move(num):
    return abs(num - FIRST_POSITION)


num = int(input()) #목적지
broken = int(input()) #고장난 숫자 개수
lis = [0,1,2,3,4,5,6,7,8,9] #다이얼 리스트
if broken > 0:
    brokenList = list(map(int,input().split())) #고장난 숫자 리스트
    for i in brokenList: # 멀쩡한 버튼만 남기기
        lis.remove(i)

a = move(num)
b = jump(num, lis)

print(min(a,b))