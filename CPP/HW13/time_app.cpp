#include "time.h"

int main(){

  Time time1(4, 5, 27);

  cout << "원래 시간: ";
  time1.print();

  for (int i = 0; i < 143500; i++){
    time1.tick();
  }

  cout << "143500초 후 시간: ";
  time1.print();

  return 0;
}
