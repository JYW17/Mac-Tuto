#include <iostream>

using namespace std;

int main(){

  int month, day;
  int rst = 0;

  cout << "Enter a month: ";
  while(true) {
    cin >> month;
    if (month < 1 || month > 12) {
      cout << "Invalid input. Please Retype your month: ";
    } else break;
  }
  
  cout << "Enter a day: ";
  while(true) {
    cin >> day;
    if (month == 2) {
      if (day < 1 || day > 28) {
        cout << "Invalid input. Please Retype your day: ";
      } else break;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
      if (day < 1 || day > 30) {
        cout << "Invalid input. Please Retype your day: ";
      } else break;
    } else {
      if (day < 1 || day > 31) {
        cout << "Invalid input. Please Retype your day: ";
      } else break;
    }
  }

  switch(month){
    case 12:
      rst += 30;
    case 11:
      rst += 31;
    case 10:
      rst += 30;
    case 9:
      rst += 31;
    case 8:
      rst += 31;
    case 7:
      rst += 30;
    case 6:
      rst += 31;
    case 5:
      rst += 30;
    case 4:
      rst += 31;
    case 3:
      rst += 28;
    case 2:
      rst += 31;
    case 1:
      ;
  }

  rst += day;

  cout << month << "월 " << day << "일은 " << rst << "번째 날입니다." << endl;

  return 0;
}
