import sys
input = sys.stdin.readline

if __name__ == '__main__':
    t = int(input().rstrip())
    
    dp = [0,1,2,4,7]
    
    for i in range(t):
        n = int(input().rstrip())
        
        if n >= len(dp):
            for i in range(len(dp),n+1):
                dp.append(dp[i-1]+dp[i-2]+dp[i-3])
        
        print(dp[n])