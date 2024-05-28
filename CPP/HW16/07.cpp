#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int arr[], int size){
  for (int i = 0; i < size; i++){
    cout << setw(2) << arr[i] << " ";
  }
  cout << endl;
}

int main(){

  int arr[20];
  srand(time(0));
  for (int i = 0; i < 20; i++){
    arr[i] = rand() % 100;
  }

  int oddnum[10];
  int evennum[10];

  for (int i = 0; i < 20; i++){
    if (i % 2 == 0){
      evennum[i/2] = arr[i];
    } else {
      oddnum[i/2] = arr[i];
    }
  }
  
  cout << "원본 배열" << endl;
  printArray(arr, 20);
  cout << "홀수 배열" << endl;
  printArray(oddnum, 10);
  cout << "짝수 배열" << endl;
  printArray(evennum, 10);
  

  return 0;
}