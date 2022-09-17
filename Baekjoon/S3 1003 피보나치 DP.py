def facto(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * facto(n-1)

print(facto(10))
