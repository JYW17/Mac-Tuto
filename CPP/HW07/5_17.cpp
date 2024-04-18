#include <iostream>

using namespace std;

int main(){

  int num;

  do{
    cout << "양의 정수를 입력하세요: ";
    cin >> num;
  } while(num < 0);

  if (num == 1) {
    cout << "1은 소수도 합성수도 아닙니다." << endl;
    return 0;
  }

  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      cout << num << "은(는) 합성수입니다." << endl;
      cout << i << "로 나누어 떨어집니다." << endl;
      return 0;
    }
  }

  cout << num << "은(는) 소수입니다." << endl;
  return 0;
}
