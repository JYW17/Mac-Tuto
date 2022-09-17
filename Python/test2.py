class Person:
    
    def __init__(self):
        pass
    
    def __init__(self, name, age, num):
        self.name = name
        self.age = age
        self.num = num

a = Person()
b = Person("이름", 10, "010 1234 1234")

print(a)
print(b)






def manyParameters(num, *args):
    print(num)
    for i in args:
        print(i)

manyParameters(10, "문자열", 20, 30, 40)
