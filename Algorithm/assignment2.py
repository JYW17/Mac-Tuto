import random


def hanoi(n, start, mid, end):
    '''
    n: 원판의 개수
    start: 출발지
    mid: 경유지
    end: 도착지
    '''
    
    if n == 1:
        print(start, '-->', end)
    else:
        # n-1개의 원판을 start에서 end를 경유지로 사용하여 mid로 옮기는 과정
        hanoi(n-1, start, end, mid)
        # 가장 큰 원판을 start에서 end로 옮기는 과정
        print(start, '-->', end)
        # n-1개의 원판을 mid에서 start를 경유지로 사용하여 end로 옮기는 과정
        hanoi(n-1, mid, start, end)


def useScale(arr, start, end):
    if start == end:
        return start
    else:
        index1 = start + (end-start+1)//3
        index2 = start + 2*(end-start+1)//3
        
        arr1 = arr[start:index1]
        arr2 = arr[index1:index2]
        
        sum1 = sum(arr1)
        sum2 = sum(arr2)
        
        if sum1 > sum2:
            return useScale(arr, start, index1-1)
        elif sum1 < sum2:
            return useScale(arr, index1, index2-1)
        else:
            return useScale(arr, index2, end)


if __name__ == '__main__':
    # '''
    # hanio 설명: 3개의 원판을 A에서 C로 옮기는 과정을 출력
    # 상세 설명: 3개의 원판을 A에서 B로 옮기고, B에서 C로 옮기는 과정을 출력
    # '''
    # hanoi(3, 'A', 'B', 'C')
    # print()
    
    # hanoi(7, 'A', 'B', 'C')
    # '''
    # 7개의 원판을 A에서 C로 옮기는 과정을 출력
    # '''
    
    n = 3**7
    coin = random.randint(0,n-1)
    arr = [0 for i in range(n)]
    arr[coin] = 1
    
    print('coin:', coin)
    print('index:', useScale(arr, 0, n-1))