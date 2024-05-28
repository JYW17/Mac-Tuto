#include <iostream>

using namespace std;

void print(int (*arr)[4], int rows){
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < 4; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){

  int arr[3][4] = {
    {10, 11, 12, 13},
    {20, 21, 22, 23},
    {31, 32, 33, 34}
  };
  print(arr, 3);

  
  return 0;
}
