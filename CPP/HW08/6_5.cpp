#include <iostream>

using namespace std;

int main(){

  char ch;
  int count = 0;

  cout << "문자열을 입력하세요. 종료는 Win(ctl + z) Mac(ctl + d)입니다." << endl;

  while(cin >> noskipws >> ch){
    if(isalpha(ch)){
      count++;
    }
    ch = toupper(ch);
    cout << ch;
  }

  cout << "알파벳의 개수: " << count << endl;

  return 0;
}