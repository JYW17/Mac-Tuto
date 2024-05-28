#include <iostream>
#include <iomanip>

using namespace std;

void printArray(const int array[][4], int rowsize, int colsize){
  for (int i = 0; i < rowsize; i++){
    for (int j = 0; j < colsize; j++){
      cout << setw(3) << array[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void printTransposedArray(const int array[][3], int rowsize, int colsize){
  for (int i = 0; i < rowsize; i++){
    for (int j = 0; j < colsize; j++){
      cout << setw(3) << array[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void printLinearArray(const int array[], int size){
  for (int i = 0; i < size; i++){
    cout << setw(3) << array[i];
  }
  cout << endl;
}

int main(){

  const int rowsize = 3;
  const int colsize = 4;

  int originalArray[rowsize][colsize] = {
    {0,   1,  2,  3},
    {10, 11, 12, 13},
    {20, 21, 22, 23}
  };

  cout << "원본 배열" << endl;
  printArray(originalArray, rowsize, colsize);

  int foldedArray[rowsize][colsize] = {0};



  cout << "행으로 배열 접기" << endl;
  for (int i = 0; i < rowsize; i++){
    for (int j = 0; j < colsize; j++){
      foldedArray[i][j] = originalArray[rowsize - 1 - i][j];
    }
  }
  printArray(foldedArray, rowsize, colsize);

  cout << "열로 배열 접기" << endl;
  for (int i = 0; i < rowsize; i++){
    for (int j = 0; j < colsize; j++){
      foldedArray[i][j] = originalArray[i][colsize - 1 - j];
    }
  }
  printArray(foldedArray, rowsize, colsize);

  cout << "전치 배열" << endl;
  int transposedArray[colsize][rowsize] = {0};
  for (int i = 0; i < colsize; i++){
    for (int j = 0; j < rowsize; j++){
      transposedArray[i][j] = originalArray[j][i];
    }
  }
  printTransposedArray(transposedArray, colsize, rowsize);

  cout << "선형 변환(행 방향)" << endl;
  int linearArray[rowsize * colsize] = {0};
  int index = 0;
  for (int i = 0; i < rowsize; i++){
    for (int j = 0; j < colsize; j++){
      linearArray[index++] = originalArray[i][j];
    }
  }
  printLinearArray(linearArray, rowsize * colsize);
  
  cout << "선형 변환(열 방향)" << endl;
  index = 0;
  for (int i = 0; i < colsize; i++){
    for (int j = 0; j < rowsize; j++){
      linearArray[index++] = originalArray[j][i];
    }
  }
  printLinearArray(linearArray, rowsize * colsize);
  
  // cout << "선형 변환(지그재그)" << endl;
  // index = 0;
  
  // printLinearArray(linearArray, rowsize * colsize);

  return 0;
}