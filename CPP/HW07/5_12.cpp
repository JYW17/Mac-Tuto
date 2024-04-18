#include <iostream>

using namespace std;

int main(){

  int input;
  short left_num = 0;
  
  do{
    cout << "음수가 아닌 정수를 입력하세요: ";
    cin >> input;
  } while(input < 0);

  while(input > 0){
    left_num = input % 10;
    input /= 10;
  }

  cout << "가장 왼쪽의 숫자: " << left_num << endl;

  return 0;
}
