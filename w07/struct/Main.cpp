#include <iostream>
#include <string>

using namespace std;

// type alias
using DataType = int;

#include "SinglyLinkedList.h"

int main() {
  SinglyLinkedList One(1);
  SinglyLinkedList Two(2, &One);

  // use l-value constructor
  DataType three = 3; // three: l-value
  SinglyLinkedList Three(three, &Two);

  SinglyLinkedList* lCurrent = &Three;  // using pointer
  
  cout << "Linked list:" << endl;
  for ( ; lCurrent != nullptr; lCurrent = lCurrent->fNext) {
    cout << "Value: " << lCurrent->fData << endl;
  }

  return 0;
}