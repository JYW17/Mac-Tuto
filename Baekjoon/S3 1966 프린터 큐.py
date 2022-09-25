def solution():
    n,m = map(int,input().split())
    imp = list(map(int,input().split()))
    que = [0 for i in range(n)]
    que[m] = "target"
    count = 1 #결과값
    
    while True:
        if imp[0] == max(imp) and que[0] == "target":
            break
        if imp[0] == max(imp):
            imp.pop(0)
            que.pop(0)
            count += 1
        else:
            imp.append(imp.pop(0))
            que.append(que.pop(0))
    
    return count      

if __name__ == "__main__":
    
    testCase = int(input())
    for i in range(testCase):
        print(solution())
