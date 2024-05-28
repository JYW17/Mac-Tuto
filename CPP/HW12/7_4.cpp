#include <iostream>
#include <cassert>

using namespace std;

class Rectangle{
  private:
    double width;
    double height;
  
  public:
    Rectangle(double width, double height);
    Rectangle(const Rectangle &rectangle);
    ~Rectangle();
  
    void print() const;
    double getArea() const;
    double getPerimeter() const;
};

Rectangle::Rectangle(double wid, double hei)
:width(wid), height(hei)
{
  if (width <= 0 || height <= 0){
    cout << "Rectangle 객체를 생성할 수 없습니다." << endl;
    assert(false);
  }
}

Rectangle::Rectangle(const Rectangle &rectangle)
:width(rectangle.width), height(rectangle.height)
{
  cout << "복사 생성자 호출" << endl;
}

Rectangle::~Rectangle(){
}

void Rectangle::print() const{
  cout << width << " x " << height << endl; 
}

double Rectangle::getArea() const{
  return width * height;
}

double Rectangle::getPerimeter() const{
  return 2 * (width + height);
}


int main(){

  Rectangle rect1(3.0, 4.0);
  Rectangle rect2(5.1, 10.2);
  Rectangle rect3(rect2);

  cout << "사각형 1: ";
  rect1.print();
  cout << "넓이: " << rect1.getArea() << endl;
  cout << "둘레: " << rect1.getPerimeter() << endl << endl;

  cout << "사각형 2: ";
  rect2.print();
  cout << "넓이: " << rect2.getArea() << endl;
  cout << "둘레: " << rect2.getPerimeter() << endl << endl;

  cout << "사각형 3: ";
  rect3.print();
  cout << "넓이: " << rect3.getArea() << endl;
  cout << "둘레: " << rect3.getPerimeter() << endl << endl;

  return 0;
}