#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  // 5번 문제
  cout << "5번 문제" << endl;
  unsigned int a;
  string b;

  cout << "Enter an integer: ";
  cin >> a;
  
  b = to_string(a);

  cout << "첫 번째 자리: " << (a%10) << endl;
  cout << "두 번째 자리: " << (a/10)%10 << endl;
  cout << "세 번째 자리: " << (a/100)%10 << endl;

  //6번 문제
  cout << endl << "6번 문제" << endl;
  unsigned int reverse_a;
  string reverse_b;

  cout << "Enter an integer: ";
  cin >> a;
  
  b = to_string(a);
  
  for(int i = b.length() - 1; i >= 0; i--){
    reverse_b += b[i];
  }
  reverse_a = stoi(reverse_b);

  cout << "reserve된 숫자: " << reverse_a << endl;

  //8번 문제
  cout << endl << "8번 문제" << endl;
  int hour, min, sec;

  cout << "시간을 입력해주세요: ";
  cin >> hour;
  
  cout << "분을 입력해주세요: ";
  while (true) {
    cin >> min;
    if (min < 0 || min > 59) {
      cout << "잘못된 입력입니다. 다시 입력해주세요: ";
    } else {
      break;
    }
  }
  
  cout << "초를 입력해주세요: ";
  while (true) {
    cin >> sec;
    if (sec < 0 || sec > 59) {
      cout << "잘못된 입력입니다. 다시 입력해주세요: ";
    } else {
      break;
    }
  }

  cout << "입력한 시간을 초로 환산하면 " << hour * 3600 + min * 60 + sec << "초입니다" << endl;

  return 0;
}
