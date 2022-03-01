#include <iostream>
#include <string>

using namespace std;

#include "SinglyLinkedList.h"
// change: SinglyLinkedListIterator2
#include "SinglyLinkedListIterator2.h"
// using parameterised class as a normal data type
using IntegerList = SinglyLinkedList<int>;
using IntegerListIterator = SinglyLinkedListIterator<int>;

void printList(const IntegerList& lst) {
  for ( const int& i : IntegerListIterator(lst)) {
    cout << "Value: " << i<< endl;
  }
}

// list operations
// factory method
IntegerList& createNew(int v, IntegerList* next = nullptr) {
  IntegerList *lst = new IntegerList(v, next);
  return *lst;
}

// append a list to end of another list
IntegerList& add(IntegerList* lst, IntegerList* newLst) {
  lst->fNext = newLst;
  return *lst;
}

// delete the next element (fNext) of a list
IntegerList& del(IntegerList* lst) {
  lst->fNext = lst->fNext->fNext;
  return *lst;
}

// insert a node at top
IntegerList& push_front(int val, IntegerList* lst) {
  IntegerList& newLst = createNew(val, lst);
  return newLst;
}

// insert a node at back
IntegerList& push_back(int val, IntegerList* lst) {
  // search for end node and sets val to be its value
  IntegerList** endPtr = &lst;  // **: pointer-to-pointer
  while (*endPtr != nullptr) {
    endPtr = &((*endPtr)->fNext);
  }

  *endPtr = new IntegerList(val);

  return *lst;
}

int main() {
  // moved to global, for use in other functions
  /*   using IntegerList = SinglyLinkedList<int>;
    using IntegerListIterator = SinglyLinkedListIterator<int>;
  */

  IntegerList One = createNew(1);         // IntegerList One(1);
  IntegerList Two = createNew(2, &One);   // IntegerList Two(2, &One);
  IntegerList lst = createNew(3, &Two); // IntegerList lst(3, &Two);

  // change: lst is passed in as l-value
  cout << "Created:" << endl;
  printList(lst);

  // add
  IntegerList Four = createNew(4);
  add(&One, &Four);
  cout << "Added:" << endl;
  printList(lst);
  
  // delete
  del(&lst);
  cout << "Deleted a node:" << endl;
  printList(lst);

  // push front
  IntegerList newLst = push_front(10, &lst);
  cout << "Pushed-front:" << endl;
  printList(newLst);

  // push front
  push_back(100, &newLst);
  cout << "Pushed-back:" << endl;
  printList(newLst);

  return 0;
}