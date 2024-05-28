#include <iostream>

using namespace std;

void reverse(int arr[], int size){
  int i = 0, j = size -1, temp;
  while(i < size/2){
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
  }
}

int main(){

  int arr[5] = {10, 11, 12, 13, 14};
  reverse(arr, 5);
  cout << "배열 거꾸로 출력" << endl;
  for(int i = 0; i < 5; i++){
    cout << arr[i] << " ";
  }
  
  return 0;
}
