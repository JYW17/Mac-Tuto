#include <iostream>

using namespace std;

int main(){

  int low = 5;
  int high = 15;

  int num;
  int guess;
  int tryLimit = 5;
  int count = 0;

  bool found = false;

  srand(time(0));
  int temp = rand();
  num = temp % (high - low + 1) + low;

  while(tryLimit > 0){
    
    do {
      cout << "숫자를 입력하세요(5~15): ";
      cin >> guess;
    } while (guess < low || guess > high);

    if (guess == num) {
      found = true;
    } else if (guess > num) {
      cout << "입력한 숫자가 높습니다." << endl;
    } else {
      cout << "입력한 숫자가 낮습니다." << endl;
    }
    count++;
    tryLimit--;

    if (found){
      cout << endl;
      cout << "*정답입니다.*" << endl;
      cout << "시도 횟수: " << count << endl;
      break;
    } else if (tryLimit == 0) {
      cout << endl;
      cout << "시도 횟수를 모두 사용하셨습니다." << endl;
      cout << "정답은 " << num << "입니다." << endl;
    }

  }

  return 0;
}