#include "iostream"
#include "SimpleClass.h"

using namespace std;

void objUse1() {
  // sc: object or reference type
  SimpleClass sc = SimpleClass();
  cout << "Created: " << sc.getName() << endl;
  sc.setName("New name");
  cout << "Updated: " << sc.getName() << endl;
}

void objUse2() {
  // sc: pointer type
  SimpleClass * sc = new SimpleClass();
  cout << "Created(2): " << sc->getName() << endl;
  // replace 'sc->' by dereference (*sc).
  (*sc).setName("New name2");
  cout << "Updated(2): " << sc->getName() << endl;
}

int main() {
  objUse1();

  objUse2();
}