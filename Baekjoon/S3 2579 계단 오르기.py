import sys
input = sys.stdin.readline

n = int(input().rstrip())
arr = [0]
dp = [0 for i in range(n+1)]

for i in range(n):
    arr.append(int(input().rstrip()))

if n >= 2:
    dp[1] = arr[1]
    dp[2] = max(dp[0]+arr[2], dp[1]+arr[2])
    for i in range(3, n+1):
        dp[i] = max(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i])

    print(dp[n])
elif n == 0:
    print(0)
elif n == 1:
    print(arr[1])
else:
    print("이건 출력되면 안 되는 문구임. 입력값 이상함 다시 보셈")