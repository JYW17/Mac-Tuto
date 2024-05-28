#include <cmath>
#include <cassert>
#include "time.h"


Time::Time()
: hour(0), minute(0), second(0)
{}

Time::Time(int h, int m, int s)
: hour(h), minute(m), second(s)
{
  normalize();
}

Time::~Time()
{}

void Time::print() const{
  cout << hour << ":" << minute << ":" << second << endl;
}

void Time::tick(){
  second++;
  normalize();
}

void Time::normalize(){
  if ((hour < 0) || (minute < 0) || (second < 0)){
    cout << "유효하지 않은 값입니다." << endl;
    assert(false);
  }

  if (second > 59){
    minute += second / 60;
    second = second % 60;
  }

  if (minute > 59){
    hour += minute / 60;
    minute = minute % 60;
  }

  if (hour > 23){
    hour = hour % 24;
  }
}