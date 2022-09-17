from sys import stdin


def solution(num):
    sum = 0
    for i in range(num):
        sum += int(stdin.readline())
    
    if sum > 0:
        print("+")
    elif sum == 0:
        print(0)
    else:
        print("-")

for i in range(3):
    solution(int(stdin.readline()))
