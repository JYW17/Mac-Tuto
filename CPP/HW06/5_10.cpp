#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  int start_num = 1,
      end_num = 300,
      divisor = 7,
      col = 1;

  for (int i = start_num; i <= end_num; i++) {
    
    if (i % divisor == 0) {
      cout << setw(4) << i;
      col++;
    }
    if (col > 10) {
      cout << endl;
      col = 1;
    }
  }
  cout << endl;

  return 0;
}
