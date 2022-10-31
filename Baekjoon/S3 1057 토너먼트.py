import sys
input = sys.stdin.readline

n, jimin, hansu = map(int, input().split())

rst = 1
while True:
    
    if ((jimin % 2 == 0) and (jimin - 1 == hansu)) or ((hansu % 2 == 0) and (hansu - 1 == jimin)):
        break
    else:
        rst += 1
        if n%2 == 0:
            n = n//2
        else:
            n = n//2 + 1
        
        if jimin%2 == 0:
            jimin = jimin//2
        else:
            jimin = jimin//2 + 1
        
        if hansu%2 == 0:
            hansu = hansu//2
        else:
            hansu = hansu//2 + 1
    
    # print("n:", n, "jimin:", jimin, "hansu:", hansu)

print(rst)