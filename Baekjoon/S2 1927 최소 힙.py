import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input().rstrip())
    lis = list()
    for i in range(n):
        x = int(input().rstrip())
        
        if x == 0:
            if lis:
                temp = min(lis)
                print(temp)
                lis.remove(temp)
            else:
                print(0)
        else:
            lis.append(x)