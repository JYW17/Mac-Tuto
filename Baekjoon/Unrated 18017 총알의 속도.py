c = 299792458.0
a, b = map(float, input().split())
print((a+b)/(1+(a*b)/(c*c)))