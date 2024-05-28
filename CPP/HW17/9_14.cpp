#include <iostream>

using namespace std;

int main(){

  int size;
  int *pArr;

  do{
    cout << "배열의 크기 입력: ";
    cin >> size;
  } while(size <= 0);

  pArr = new int[size];

  for (int i = 0; i < size; i++){
    cout << i + 1 << "번째 요소의 값 입력: ";
    cin >> pArr[i];
  }

  cout << "입력한 배열: ";
  for (int i = 0; i < size; i++){
    cout << pArr[i] << " ";
  }

  return 0;
}
