#ifndef PERSON_H
#define PERSON_H

#include "date.h"

class Person{
  private:
    long identity;
    Date birthdate;
  public:
    Person(long i, Date d);
    ~Person();
    void print();
};

#endif