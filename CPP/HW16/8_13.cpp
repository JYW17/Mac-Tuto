#include <iostream>
#include <iomanip>

using namespace std;

void findStudentAverage(const int score[][3], double stuAver[], int rowsize, int colsize){

  int sum = 0;
  
  for (int i = 0; i < rowsize; i++){
    sum = 0;
    for (int j = 0; j < colsize; j++){
      sum += score[i][j];
    }
    stuAver[i] = static_cast<double>(sum) / colsize;
  }
}

void findTestAverage(const int score[][3], double testAver[], int rowsize, int colsize){

  int sum = 0;
  
  for (int i = 0; i < colsize; i++){
    sum = 0;
    for (int j = 0; j < rowsize; j++){
      sum += score[j][i];
    }
    testAver[i] = static_cast<double>(sum) / rowsize;
  }
}

int main(){

  const int rowsize = 5;
  const int colsize = 3;

  int score[rowsize][colsize] = {
    {82, 65, 72},
    {73, 70, 80},
    {91, 67, 40},
    {72, 72, 68},
    {65, 90, 80}};
  
  double stuAver[rowsize];
  double testAver[colsize];

  findStudentAverage(score, stuAver, rowsize, colsize);
  findTestAverage(score, testAver, rowsize, colsize);

  cout << "         시험 점수                    평균" << endl;
  cout << "         --------------------------- ------" << endl;
  for (int i = 0; i < rowsize; i++){

    for (int j = 0; j < colsize; j++){
      cout << setw(12) << score[i][j];

    }
    cout << "  " << fixed << setprecision(2) << stuAver[i] << endl;
  }
  cout << "         ---------------------------" << endl;
  cout << "최종 점수 ";
  for (int j = 0; j < colsize; j++){
    cout << fixed << setprecision(2) << testAver[j] << "       ";
  }

  return 0;
}