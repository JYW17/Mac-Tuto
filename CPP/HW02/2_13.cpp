#include <iostream>
#include <string>

using namespace std;

int main() {

  string first;
  string initial;
  string last;
  string fullName;
  string dot = ".";
  string space = " ";

  cout << "이름(first name) 입력하기: ";
  cin >> first;
  cout << "이니셜(initial) 입력하기: ";
  cin >> initial;
  cout << "성(last name) 입력하기: ";
  cin >> last;

  fullName = first + space + initial + dot + space + last;

  cout << "전체 이름(full name): " << fullName << endl;
  return 0;
}