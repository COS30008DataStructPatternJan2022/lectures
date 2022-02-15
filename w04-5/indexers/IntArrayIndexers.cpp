#include <string>
// #include <exception>
#include <iostream>
#include "IntArrayIndexers.h"

#include "../../../utils/functions/Functions.cpp"

using namespace std;

using namespace toolkit;

/*
  * operator: this[aKey] 
  * post
  *  result = e in fArrayElements that is mapped to aKey
  */
const int& IntArrayIndexer::operator[] (const string& aKey) const {
  int lIndex = 0;
  // convert aKey to corresponding numeric value
  // e.g. "1" -> 1; "11" -> 11; "111" -> 111
  for (unsigned int i = 0; i < aKey.length(); i++) {
    lIndex = lIndex * 10 + (aKey[i] - '0');
  }

  cout << "key: \"" << aKey << "\" -> index: " << lIndex << endl;

  if (lIndex < fLength) {
    return fArrayElements[lIndex];
  } else {
    throw out_of_range("Index out of bounds: " + aKey);
  }
}

int main() {
  int a[] = {1,2,3,4,5,100};
  // traditional: a[0], a[1],...

  int len = 6;
  // cout << "Array: " << a << "; length: " << len << endl;
  cout << "Creating indexer for array" << endl;
  IntArrayIndexer indexer(a, len);

  string keys[] = {"0", "1", "2", "3", "4", "5"};
  int Sum = 0;

  // 
  string key = keys[1];
  int val = indexer[key];
  cout << "indexer[\"" << key << "\"] = " << val << endl;

  for (int i = 0; i < len; i++) {
    //Sum += indexer[keys[i]];
    // previously: indexer++, indexer += otherIndexer
    string key = keys[i];
    Sum += indexer[key]; // operator []
  }

  cout << "Indexed sum of " << arrToString(a, len) << " is " << Sum << endl;

  return 0;
}