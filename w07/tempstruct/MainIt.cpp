#include <iostream>
#include <string>

using namespace std;

#include "SinglyLinkedList.h"
#include "SinglyLinkedListIterator.h"

// using parameterised class as a normal data type
using IntegerList = SinglyLinkedList<int>;
using IntegerListIterator = SinglyLinkedListIterator<int>;

// list operations
IntegerList& createNew(int v, IntegerList* next = nullptr) {
  IntegerList *lst = new IntegerList(v, next);
  return *lst;
}

int main() {
  // moved to global, for use in other functions
  /*   using IntegerList = SinglyLinkedList<int>;
    using IntegerListIterator = SinglyLinkedListIterator<int>;
  */

  // create list
  IntegerList One = createNew(1);         // IntegerList One(1);
  IntegerList Two = createNew(2, &One);   // IntegerList Two(2, &One);
  IntegerList Three = createNew(3, &Two); // IntegerList Three(3, &Two);

  IntegerList* lTop = &Three;
  
  //  create list iterator
  IntegerListIterator it(&Three);

  // for-range loop: easier to code!
  for ( const int& i : it) {  // or IntegerListIterator(&Three)
    cout << "Value: " << i<< endl;
  }

  return 0;
}