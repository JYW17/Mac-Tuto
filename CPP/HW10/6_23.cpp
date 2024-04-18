#include <iostream>

using namespace std;

void func();

int main(){

  func();
  func();
  func();

  return 0;
}

void func(){
  static int num = 0;
  num++;

  cout << "num: " << num << endl;
}