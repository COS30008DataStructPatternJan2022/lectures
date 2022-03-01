#include <iostream>
#include <string>

using namespace std;

#include "SinglyLinkedList.h"

int main() {
  // Type alias: using parameterised class as a normal data type
  using IntegerList = SinglyLinkedList<int>;

  IntegerList One(1);
  IntegerList Two(2, &One);
  IntegerList Three(3, &Two);

  IntegerList* lTop = &Three;
  
  for ( ; lTop != nullptr; lTop = lTop->fNext) {
    cout << "Value: " << lTop-> fData << endl;
  }

  return 0;
}