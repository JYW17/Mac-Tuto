#include "person.h"

int main(){

  Date date1(5, 6, 1980);
  Person person1(123456789, date1);
  Date date2(4, 23, 1973);
  Person person2(222222222, date2);

  person1.print();
  person2.print();

  return 0;
}
