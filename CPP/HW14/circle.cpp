#include "circle.h"

//생성자
Circle::Circle()
: radius(0)
{}

Circle::Circle(double rds)
: radius(rds)
{
    if (radius < 0){
    assert(false);
  }
}

//소멸자
Circle::~Circle()
{}

//복사 생성자
Circle::Circle(const Circle &circle)
: radius(circle.radius)
{}

//멤버 함수
void Circle::setRadius(double rds)
{
  radius = rds;
}

double Circle::getRadius() const
{
  return radius;
  if (radius < 0){
    assert(false);
  }
}

double Circle::getArea() const
{
  const double PI = 3.14;
  return PI * radius * radius;
}

double Circle::getPerimeter() const
{
  const double PI = 3.14;
  return 2 * PI * radius;
}
