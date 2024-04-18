#include <iostream>

using namespace std;

int global;

int main(){

  static int sLocal;
  int local;

  cout << "global: " << global << endl;
  cout << "sLocal: " << sLocal << endl;
  cout << "local: " << local << endl;

  return 0;
}
