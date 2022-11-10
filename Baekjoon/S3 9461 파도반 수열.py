dp = [0,1,1,1,2,2,3,4,5,7,9]
for i in range(11,101):
    dp.append(dp[i-1] + dp[i-5])

t = int(input())
for i in range(t):
    print(dp[int(input())])