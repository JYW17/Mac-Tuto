#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  int row, col;
  int set_width = 0;

  do{
    cout << "행의 수를 입력하세요: ";
    cin >> row;
  } while(row < 1);

  do{
    cout << "열의 수를 입력하세요: ";
    cin >> col;
  } while(col < 1);

  set_width = to_string(row * col).length() + 1;

  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= col; j++) {
      cout << setw(set_width) << i * j;
    }
    cout << endl;
  }

  return 0;
}
