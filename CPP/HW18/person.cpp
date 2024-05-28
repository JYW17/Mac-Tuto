#include "person.h"

Person::Person(long i, Date d)
:identity(i), birthdate(d){
  assert(identity > 111111111 && identity < 999999999);
}

Person::~Person(){
}

void Person::print(){
  cout << "Identity: " << identity << endl;
  cout << "Birthdate: ";
  birthdate.print();
}