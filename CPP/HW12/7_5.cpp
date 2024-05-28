#include <iostream>

using namespace std;

class Rectangle{
  private:
    double width;
    double height;
    static int count;

  public:
    Rectangle(double width, double height);
    Rectangle();
    ~Rectangle();
    Rectangle(const Rectangle &rectangle);
  
    static int getCount();
};

int Rectangle::count = 0;

Rectangle::Rectangle(double wid, double hei)
:width(wid), height(hei)
{
  count++;
}

Rectangle::Rectangle()
:width(0), height(0)
{
  count++;
}

Rectangle::Rectangle(const Rectangle &rectangle)
:width(rectangle.width), height(rectangle.height)
{
  count++;
}

Rectangle::~Rectangle(){
  count--;
}


int Rectangle::getCount(){
  return count;
}


int main(){

  {
    Rectangle rect1(3.2, 1.2);
    Rectangle rect2(1.5, 2.1);
    Rectangle rect3;
    Rectangle rect4(rect1);
    Rectangle rect5(rect2);

    cout << "객체의 수: " << rect5.getCount() << endl;
  }
  
  cout << "객체의 수: " << Rectangle::getCount() << endl;
  
  return 0;
}
