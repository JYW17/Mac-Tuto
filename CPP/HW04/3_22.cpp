#include <iostream>

using namespace std;

int main(void){

  int x = 1237;

  cout << "x in decimal: " << x << endl;
  cout << "x in octal: " << oct << x << endl;
  cout << "x in hexadecimal: " << hex << x << endl << endl;

  cout << "x in decimal: " << dec << x << endl;
  cout << "x in octal: " << showbase << oct << x << endl;
  cout << "x in hexadecimal: " << showbase << hex << x << endl;

  return 0;
}