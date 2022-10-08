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

st = '12345'
index = -2
rst = st[:index] + "." + st[index:]
print(rst)