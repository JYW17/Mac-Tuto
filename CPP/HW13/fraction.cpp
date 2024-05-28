#include <iostream>
#include <cassert>
#include <cmath>
#include "fraction.h"

using namespace std;

Fraction::Fraction()
:numer(0), denom(1)
{}

Fraction::Fraction(int num, int den = 1)
:numer(num), denom(den)
{
  normalize();
}

Fraction::~Fraction()
{}

Fraction::Fraction(const Fraction& f)
:numer(f.numer), denom(f.denom)
{}

int Fraction::getNumer() const
{
  return numer;
}

int Fraction::getDenom() const
{
  return denom;
}

void Fraction::print() const
{
  cout << numer << "/" << denom << endl;
}

void Fraction::setNumer(int num)
{
  numer = num;
  normalize();
}

void Fraction::setDenom(int den)
{
  denom = den;
  normalize();
}

void Fraction::normalize()
{
  if (denom == 0){
    cout << "분모가 0일 수 없습니다. 프로그램을 중단합니다." << endl;
    assert(false);
  }

  if (denom < 0){
    numer *= -1;
    denom *= -1;
  }

  int divisor = gcd(abs(numer), abs(denom));
  numer /= divisor;
  denom /= divisor;
}

int Fraction:: gcd(int a, int b)
{
  int gcd = 1;
  for (int i = 1; i <= a && i <=b; i++){
    if (a % i == 0 && b % i == 0){
      gcd = i;
    }
  }
  return gcd;
}
