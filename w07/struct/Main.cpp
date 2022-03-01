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
  DataType three = 3;
  SinglyLinkedList Three(three, &Two);

  SinglyLinkedList* lTop = &Three;  // using pointer
  
  cout << "Linked list:" << endl;
  for ( ; lTop != nullptr; lTop = lTop->fNext) {
    cout << "Value: " << lTop-> fData << endl;
  }

  return 0;
}