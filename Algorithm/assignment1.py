import time
import datetime

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
    
    for n in [10, 50, 70]:
        # 반복문 실행 시간 확인
        print("n의 값이 {}일 때".format(n))
        start = time.time()
        print("반복문의 피보나치 값:", fiboIteration(n))
        end = time.time()
        iterationSec = end - start
        print("반복문 실행 시간:", datetime.timedelta(seconds = iterationSec))
        print()
    
    for n in [10, 20, 30, 40, 50]:
        print("n의 값이 {}일 때".format(n))
        print()
        # 재귀문 실행 시간 확인
        start = time.time()
        print("재귀문의 피보나치 값:", fiboRecursion(n))
        end = time.time()
        recursionSec = end - start
        print("재귀문 실행 시간:", datetime.timedelta(seconds = recursionSec))
        print()
