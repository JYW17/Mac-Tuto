#include <iostream>

using namespace std;

int main(){

  const int CAPACITY = 10;
  int number[CAPACITY];
  int size;

  do{
    cout << "크기를 입력하세요: ";
    cin >> size;
  } while(size < 1 || size > CAPACITY);

  cout << size << "개의 숫자를 입력하세요: " << endl;
  for (int i = 0; i < size; i++){
    cin >> number[i];
  }

  cout << "입력된 숫자 거꾸로 출력" << endl;
  for (int i = size - 1; i >= 0; i--){
    cout << number[i] << " ";
  }
  
  return 0;
}