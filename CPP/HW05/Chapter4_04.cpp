#include <iostream>

using namespace std;

int main(){

  int credit;

  cout << "Enter your credit: ";
  
  while(true){
    cin >> credit;

    if (credit == 0) {
      cout << "You have no tuition" << endl;
      return 0;
    }

    if (credit < 0) {
      cout << "Invalid input. Please Retype your credit: ";
    } else break;
  }

  if (credit > 12) credit = 12;

  cout << "Your tuition is " << credit * 10 + 10 << endl;

  return 0;
}
