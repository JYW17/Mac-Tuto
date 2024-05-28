#include <iostream>

using namespace std;

#ifndef FRACTION_H
#define FRACTION_H

class Fraction{
  //멤버 변수
  private:
    int numer;
    int denom;
  
  //멤버 함수
  public:
    Fraction();
    Fraction(int num, int den);
    ~Fraction();
    Fraction(const Fraction& f);

    int getNumer() const;
    int getDenom() const;
    void print() const;

    void setNumer(int num);
    void setDenom(int den);

  private:
    void normalize();
    int gcd(int a, int b);
};
#endif
