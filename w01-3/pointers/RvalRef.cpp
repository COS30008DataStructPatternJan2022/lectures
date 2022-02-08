#include <iostream>
#include <string>

using namespace std;

void changeVal(int&& rVal) {
  cout << "func()" << endl;

  int old = std::move(rVal);
  old = rVal; // also works

  rVal = 100;
  cout << old << " -> " << rVal << endl;
}

int main() {
  int val = 10;

  // error
  // int&& rrefVal = val;

  int&& rrefVal = 10;
  
  // move: converts val to an r-value reference, and therefore can change it
  int&& rrefVal = std::move(val);
  cout << rrefVal << endl;

  rrefVal = 20;
  cout << rrefVal << endl;

  changeVal(10);
  // errors: changeVal(val); changeVal(rrefVal);
}

