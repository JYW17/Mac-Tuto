#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  cout << "short int의 크기는 " << sizeof(short int) << "바이트입니다." << endl;
  cout << "int의 크기는 " << sizeof(int) << "바이트입니다." << endl;
  cout << "long int의 크기는 " << sizeof(long int) << "바이트입니다." << endl;
  
  cout << "표현식의 크기는 " << sizeof(3 + 4.5) << "바이트입니다." << endl;
  cout << "표현식의 자료형은 " << typeid(3 + 4.5).name() << "입니다." << endl;

  return 0;
}
