# class Person:
    
#     def __init__(self):
#         pass
    
#     def __init__(self, name, age, num):
#         self.name = name
#         self.age = age
#         self.num = num

# a = Person()
# b = Person("이름", 10, "010 1234 1234")

# print(a)
# print(b)

# def manyParameters(num, *args):
#     print(num)
#     for i in args:
#         print(i)

# manyParameters(10, "문자열", 20, 30, 40)


# from abc import *
# from operator import methodcaller
# class StudentBase(metaclass = ABCMeta):
#     @abstractmethod
#     def study(self):
#         pass
#     @abstractmethod
#     def gotoschool(self):
#         pass
    
# class Student(StudentBase):
#     def study(self):
#         print("공부")
#     def gotoschool(self):
#         print("학교 가자")

# jason = Student()
# jason.study()

# from abc import *
# class Animal(metaclass = ABCMeta):
#     @abstractclassmethod
#     def do_say(self):
#         pass

# class Dog (Animal):
#     def do_say(self):
#         print("멍 멍")

# class ForestFactory(object):
#     def make_sound(self, object_type):
#         return eval(object_type)().do_say()

# ff = ForestFactory()
# ff.make_sound("Dog")

# from collections import Counter
# n = int(input())
# cn = Counter(list(map(int, input().split())))
# v = int(input())
# print(cn[v])

# def sub(arr):
#     arr[0] = 0

# def sub2(x):
#     x += 1

# lis = [5,5,5,5,5]
# print('before sub: ', lis)
# sub(lis)
# print('after sub', lis)

# x=10
# print('before sub2: ', x)
# sub2(x)
# print('after sub2: ', x)

import time
import datetime

fibList = list()
fibList.append(0)
fibList.append(1)

start = time.time()

for n in range(2, 1000001):
    fibList.append(fibList[n-1] + fibList[n-2]) 

end = time.time()
iterationSec = end - start
print("반복문 실행 시간:", datetime.timedelta(seconds = iterationSec))
print()


