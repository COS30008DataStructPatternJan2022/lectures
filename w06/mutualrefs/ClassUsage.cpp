#include "ClassA.h"
#include "ClassB.h"
#include <iostream>

using namespace std;

// implement ClassA
ClassA::ClassA() {
  // empty
}

void ClassA::methodA(const ClassB& b) const {
  cout << "ClassA.methodA()" << endl;
  b.methodB(*this);
}

void ClassA::toString() const {
  cout << "ClassA(" << this << ")" << endl;
}

// implement ClassB
ClassB::ClassB() {
  // empty
}

void ClassB::methodB(const ClassA& a) const {
  //
  cout << "ClassB.methodB(): using object ";
  a.toString();
  cout << endl;
}

int main() {
  ClassB b;
  ClassA a;
  
  a.methodA(b);
}