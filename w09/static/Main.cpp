#include <iostream>

#include "StaticVars.cpp"

using namespace std;

// main method
int main() {
  A obj;
  obj.printStates();
  obj.update();

  A obj2;
  // update global variable
  cout << endl << "Global update";
  gCounter++;
  gLocalCounter++;
  A::PublicClassACounter++;

  obj2.printStates();

  // static function
  A::staticFunc();
  A::printStaticState();
}