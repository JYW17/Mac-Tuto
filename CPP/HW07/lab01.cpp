#include <iostream>

using namespace std;

int main(){
  
  int pattern;
  int line_size;

  do{
    cout << "패턴 타입을 선택하세요(1, 2): ";
    cin >> pattern;
  } while(pattern != 1 && pattern != 2);
  
  do{
    cout << "크기를 입력하세요(1 ~ 6): ";
    cin >> line_size;
  } while(line_size < 1 || line_size > 6);

  if(pattern == 1){
    for (int i = line_size; i >= 1; i--) {
      for (int j = 1; j <= line_size + i - 1; j++) {
        if(j < line_size - i + 1){
          cout << " ";
        } else {
          cout << "*";
        }
      }
      cout << endl;
    }
  }


  if (pattern == 2) {
    
    for (int i = 1; i <= line_size; i++) {
      for (int j = 1; j <= line_size + i - 1; j++) {
        if(j < line_size - i + 1){
          cout << " ";
        } else {
          cout << "*";
        }
      }
      cout << endl;
    }
  }

  return 0;
}