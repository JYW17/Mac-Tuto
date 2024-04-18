#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  int days, start_day;

  do {
    cout << "한 달의 날짜 수를 입력하세요(28,29,30,31): ";
    cin >> days;
  } while ( days < 28 || days > 31);
  
  do {
    cout << "첫 날의 요일을 입력하세요(0~6): ";
    cin >> start_day;
  } while (start_day < 0 || start_day > 6);

  cout << endl;
  cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
  cout << " --- --- --- --- --- --- ---" << endl;

  int i = 1;
  int j = start_day;

  for (int i = 0; i < start_day; i++) {
    cout << setw(4) << "";
  }

  while(i <= days){
    cout << setw(4) << i;
    i++;
    j++;
    
    if(j > 6){
      cout << endl;
      j = 0;
    }
  }
  cout << endl;

  return 0;
}
