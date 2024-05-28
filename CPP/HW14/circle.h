#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cassert>

using namespace std;


class Circle{
  //멤버 변수
  private:
    double radius;
  
  public:
    //생성자
    Circle();
    Circle(double rds);
    //소멸자
    ~Circle();
    //복사 생성자
    Circle(const Circle &circle);

    //멤버 함수
    void setRadius(double rds);
    double getRadius() const;
    double getArea() const;
    double getPerimeter() const;
};
#endif
