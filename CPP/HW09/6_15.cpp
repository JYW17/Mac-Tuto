#include <iostream>

using namespace std;


int main(){

  int first = 10;
  int second = 20;

  cout << "스왑하기 전: " << "first " << first << ", " << "second " << second << endl;

  swap(first, second);

  cout << "스왑한 후: " << "  first " << first << ", " << "second " << second << endl;

  return 0;
}

void swap(int& a, int& b){
  int temp = a;
  a = b;
  b = temp;
  return;
}