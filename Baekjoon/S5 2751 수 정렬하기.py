import sys
input = sys.stdin.readline

if __name__ == "__main__":
    
    n = int(input())
    lis = []
    for i in range(n):
        lis.append(int(input()))

    lis.sort()

    for i in lis:
        sys.stdout.write(str(i) + "\n")
