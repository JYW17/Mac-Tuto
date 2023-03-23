import time
import datetime

# 연습문제 36번
def any_equel(arr):
    n = len(arr)
    start = time.time()
    for i in range(n):
        for j in range(n):
            for k in range(n):
                for m in range(n):
                    if arr[i][j] == arr[k][m] and not(i==k and j==m):
                        end = time.time()
                        sec = end - start
                        print("알고리즘 실행 시간:", datetime.timedelta(seconds = sec))
                        return 1
    end = time.time()
    sec = end - start
    print("알고리즘 실행 시간:", datetime.timedelta(seconds = sec))
    return 0

# 피보나치 재귀문
def fiboRecursion(n):
    if n < 0:
        return 'Wrong number'
    elif n <= 1:
        return n
    else:
        return fiboRecursion(n-1) + fiboRecursion(n-2)

# 피보나치 반복문
def fiboIteration(n):
    if n < 0:
        return 'Wrong number'
    elif n <= 1:
        return n
    else:
        temp1, temp2= 0, 1
        rst = 0
        for i in range(2, n+1):
            rst = temp1 + temp2
            temp1 = temp2
            temp2 = rst
    return rst


# main 함수
if __name__ == "__main__":
    print("번호 입력")
    print("1번: 연습문제 36번, 2번: 피보나치")
    ans = int(input())
    
    if ans == 1:
        '''
        가장 최선의 시간복잡도일 경우는 arr[0][0]과 arr[0][1]이 같을 때이고
        가장 최악의 시간복잡도는 모든 항이 서로 다른 값을 가질 때이다. 
        '''
        print("최선의 시간복잡도일 때")
        arr = [[1 for i in range(100)] for i in range(100)]
        print("결과값:", any_equel(arr))
        print()
        print("최악의 시간복잡도일 때")
        arr = [[0 for i in range(100)] for i in range(100)]
        value = 0
        for i in range(100):
            for j in range(100):
                arr[i][j] = value
                value += 1
        print("결과값:", any_equel(arr))
    elif ans == 2:
        for n in [10, 30, 50, 70, 80]:
            # 반복문 실행 시간 확인
            print("n의 값이 {}일 때".format(n))
            start = time.time()
            print("반복문의 피보나치 값:", fiboIteration(n))
            end = time.time()
            iterationSec = end - start
            print("반복문 실행 시간:", datetime.timedelta(seconds = iterationSec))
            print()
        
        '''
        40번째 수는 약 20초 정도 걸리고 이후 n이 10씩 증가할 때마다 걸리는 시간은 2^10만큼 증가하므로
        50번째 수를 알아내기에는 약 5시간이 걸리기 때문에 이후 값들은 생략하였습니다
        ''' 
        for n in [10, 30, 40]: 
            print("n의 값이 {}일 때".format(n))
            print()
            # 재귀문 실행 시간 확인
            start = time.time()
            print("재귀문의 피보나치 값:", fiboRecursion(n))
            end = time.time()
            recursionSec = end - start
            print("재귀문 실행 시간:", datetime.timedelta(seconds = recursionSec))
            print()
    else:
        print("입력값 오류")