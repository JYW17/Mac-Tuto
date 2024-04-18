#include <iostream>

using namespace std;


class Circle{
  //멤버 변수
  private:
    double radius;
  
  public:
    //생성자
    Circle(){radius = 0; cout << "기본 생성자 호출" << endl;}
    Circle(double rds){radius = rds; cout << "매개 변수가 있는 생성자 호출" << endl;}
    //소멸자
    ~Circle(){cout << "소멸자 호출 " << radius << endl;}
    //복사 생성자
    Circle(const Circle &circle){radius = circle.radius; cout << "복사 생성자 호출 " << radius << endl;}

    //멤버 함수
    void setRadius(double rds){radius = rds;}
    double getRadius(){return radius;}
    double getArea(){return 3.14 * radius * radius;}
    double getPerimeter(){return 2 * 3.14 * radius;}
};


int main(){

  Circle circle1(5.2);
  cout << "반지름: " << circle1.getRadius() << endl;
  cout << "넓이: " << circle1.getArea() << endl;
  cout << "둘레: " << circle1.getPerimeter() << endl << endl;

  Circle circle2(circle1);
  cout << "반지름: " << circle2.getRadius() << endl;
  cout << "넓이: " << circle2.getArea() << endl;
  cout << "둘레: " << circle2.getPerimeter() << endl << endl;

  Circle circle3;
  cout << "반지름: " << circle3.getRadius() << endl;
  cout << "넓이: " << circle3.getArea() << endl;
  cout << "둘레: " << circle3.getPerimeter() << endl << endl;

  return 0;
}
