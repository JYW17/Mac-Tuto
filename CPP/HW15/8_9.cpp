#include <iostream>
#include <iomanip>

using namespace std;

void findGrade(const int score[], char grades[], int size){
  
  char temp[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
  
  for (int i = 0; i < size; i++){
    grades[i] = temp[score[i] / 10];
  }

}

int main(){

  string names[4] = {"George", "John", "Luci", "Mary"};
  int scores[4] = {82, 73, 91, 72};
  char grades[4];
  
  findGrade(scores, grades, 4);

  for (int i = 0; i < 4; i++){
    cout << setw(10) << left << names[i] << "     ";
    cout << setw(2) << scores[i] << "     " << setw(2) << grades[i] << endl;
  }

  return 0;
}
