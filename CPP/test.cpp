#include <iostream>
#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

int main(){

  char ch = 'A';

  int i = ch;
    
  ch = i * 2;

  cout << i << endl;
  cout << ch << endl;
  cout << typeid(ch).name() << endl;


  return 0;
}
