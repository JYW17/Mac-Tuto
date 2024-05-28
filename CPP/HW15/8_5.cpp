#include <iostream>
#include <fstream>

using namespace std;

int main(){

  ifstream inputFile;

  const int capacity = 50;
  int numbers[capacity];
  int size = 0;

  int sum = 0;
  double average;
  int smallest = numeric_limits<int>::max();
  int largest = numeric_limits<int>::min();

  inputFile.open("inFIle.dat");
  if (!inputFile){
    cout << "파일을 열 수 없습니다." << endl;
    cout << "프로그램을 종료합니다." << endl;
    return 0;
  }

  while (inputFile >> numbers[size]){
    size++;
  }

  inputFile.close();

  for (int i = 0; i < size; i++){
    sum += numbers[i];
    if (numbers[i] < smallest){
      smallest = numbers[i];
    }
    if (numbers[i] > largest){
      largest = numbers[i];
    }
  }
  average = static_cast<double>(sum) / size;

  cout << "목록에 숫자가 " << size << "개 있습니다." << endl;
  cout << "합계: " << sum << endl;
  cout << "평균: " << average << endl;
  cout << "최소: " << smallest << endl;
  cout << "최대: " << largest << endl;
  
  return 0;
}