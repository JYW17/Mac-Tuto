# include "date.h"

Date::Date(int m, int d, int y)
:month(m), day(d), year(y){
  if (m < 1 || m > 12){
    cout << "Month is out of range" << endl;
    assert(false);
  }

  int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (d < 1 || d > monthDays[m - 1]){
    cout << "Day is out of range" << endl;
    assert(false);
  }

  if (y < 1900 || y > 2100){
    cout << "Year is out of range" << endl;
    assert(false);
  }
}

Date::~Date(){
}

void Date::print(){
  cout << month << "/" << day << "/" << year << endl;
}
