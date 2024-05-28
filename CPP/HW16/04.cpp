#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int arr[], int size){
  for (int i = 0; i < size; i++){
    cout << setw(2) << arr[i] << " ";
  }
  cout << endl;
}

void roundShift(int arr[], int size){
  
  int temp = arr[size-1];
  for (int i = size-1; i > 0; i--){
    arr[i] = arr[i-1];
  }
  arr[0] = temp;

}

int main(){

  int arr[10];
  srand(time(0));
  for (int i = 0; i < 10; i++){
    arr[i] = rand() % 100;
  }

  cout << "원본 배열" << endl;
  printArray(arr, 10);
  roundShift(arr, 10);
  cout << "한 칸 회전한 배열" << endl;
  printArray(arr, 10);


  return 0;
}