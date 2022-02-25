#include "IntArrayIterator.h"

/* Implementation of IntArrayIterator.h */
IntArrayIterator::IntArrayIterator(const int aArray[], const int aLength, int aStart) : 
  fArrayElements(aArray), fLength(aLength), fIndex(aStart) {
  // fIndex = aStart;
}

// dereference operator
const int& IntArrayIterator::operator*() const {
  return fArrayElements[fIndex];
}

// prefix
IntArrayIterator& IntArrayIterator::operator++() { 
  fIndex++;
  return *this;
}

// postfix (extra unused argument)
IntArrayIterator IntArrayIterator::operator++(int )  {
  IntArrayIterator temp = *this;
  ++(*this);  // reuse prefix implementation

  return temp;
}

bool IntArrayIterator::operator==(const IntArrayIterator& aOther) const {
  return (fIndex ==  aOther.fIndex) && 
    (fArrayElements == aOther.fArrayElements);
}

bool IntArrayIterator::operator!=(const IntArrayIterator& aOther) const {
  return !(*this == aOther);  // reuse operator ==
}

IntArrayIterator IntArrayIterator::begin() const {
  // return a new object
  // return IntArrayIterator(fArrayElements, fLength);  // aStart = 0 (default)

  /* 
    alternative: clone instead
   */
  IntArrayIterator Result = *this;
  Result.fIndex = 0;
  return Result;
}

IntArrayIterator IntArrayIterator::end() const {
  // return a new object
  // return IntArrayIterator(fArrayElements, fLength, fLength);

  /* 
    alternative: clone instead
   */
  IntArrayIterator Result = *this;
  Result.fIndex = fLength;
  return Result;  
}

/* END: implementation of IntArrayIterator.h  */

#include <iostream>
using namespace std;
#include "../../../utils/functions/Functions.cpp"
using namespace toolkit;

void iteratorWithFor() {
  cout << endl << "iteratorWithFor()" << endl;
  // (1) initialise the collection
  int a[] = {1,2,3,4,5,100};

  cout << "Array: "; printIntArr(a, 6); 

  // sizeof(a): size of a
  // sizeof(*a): size of element in a
  const int len = sizeof(a) / sizeof(*a); // no manual: 6
  int Sum = 0;

  // (2) Iterator object for the collection
  IntArrayIterator iter(a, len);

  // (3) Use Iterator object to process the elements (class for loop)
  for (; iter != iter.end(); iter++) {
    Sum += *iter;
  }

  cout << "Iterator sum of " << arrToString(a, len) << ": " << Sum << endl;
}

void iteratorWithForEach() {
  cout << endl << "iteratorWithForEach()" << endl;
  // (1) initialise the collection
  int a[] = {1,2,3,4,5,100};
  cout << "Array: "; printIntArr(a, 6);

  const int len = sizeof(a) / sizeof(*a);
  int Sum = 0;
  // (2) Iterator object for the collection
  IntArrayIterator iter(a, len);
  // *iter = 100;

  // (3) Use Iterator object to process the elements (new for-each loop)
  for (const auto& i : iter) {
    Sum += i;
  }

  cout << "Iterator sum of " << arrToString(a, len) << ": " << Sum << endl;
}

int main() {
  iteratorWithFor();

  iteratorWithForEach();

  return 0;
}