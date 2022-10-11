from re import L


n, m = map(int, input().split())

nhear = set()
nsee = set()

for i in range(n):
    nhear.add(input())
for i in range(m):
    nsee.add(input())

rst = nhear & nsee
rst = list(rst)
rst.sort()

print(len(rst))
for i in rst:
    print(i)