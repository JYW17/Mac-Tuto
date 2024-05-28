#include <iostream>

using namespace std;

#ifndef TIME_H
#define TIME_H

class Time{
  private:
    int hour;
    int minute;
    int second;
  
  public:
    Time();
    Time(int h, int m, int s);
    ~Time();

    void print() const;
    void tick();

  private:
    void normalize();
};

#endif