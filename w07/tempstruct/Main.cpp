#include <iostream>
#include <string>

using namespace std;

#include "SinglyLinkedList.h"

int main() {
  // instantiate the template with type 'int'
  SinglyLinkedList<int> One(1);
  SinglyLinkedList<int> Two(2, &One);
  SinglyLinkedList<int> Three(3, &Two);

  SinglyLinkedList<int>* lTop = &Three;
  
  for ( ; lTop != nullptr; lTop = lTop->fNext) {
    cout << "Value: " << lTop-> fData << endl;
  }

  return 0;
}