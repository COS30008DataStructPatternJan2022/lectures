#include "IntArrayIterator.h"
#include <iostream>

using namespace std;

/* Implementation of IntArrayIterator.h */
IntArrayIterator::IntArrayIterator(const int aArray[], const int aLength, int aStart): 
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

#include "../../../utils/functions/Functions.cpp"
using namespace toolkit;

void iteratorWithFor() {
  cout << endl << "iteratorWithFor()" << endl;
  int a[] = {1,2,3,4,5,100};

  cout << "Array: "; printIntArr(a, 6); 

  // sizeof(a): size of a
  // sizeof(*a): size of element in a
  const int len = sizeof(a) / sizeof(*a);
  int Sum = 0;

  for (IntArrayIterator iter(a, len); iter != iter.end(); iter++) {
    Sum += *iter;
  }

  cout << "Iterator sum of " << arrToString(a, len) << ": " << Sum << endl;
}

void iteratorWithForEach() {
  cout << endl << "iteratorWithForEach()" << endl;

  int a[] = {1,2,3,4,5,100};
  cout << "Array: "; printIntArr(a, 6);

  const int len = sizeof(a) / sizeof(*a);
  int Sum = 0;

  for (const auto& i : IntArrayIterator(a, len)) {
    Sum += i;
  }

  cout << "Iterator sum of " << arrToString(a, len) << ": " << Sum << endl;
}

int main() {
  iteratorWithFor();

  iteratorWithForEach();

  return 0;
}