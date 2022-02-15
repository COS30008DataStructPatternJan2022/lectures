#include <vector>
#include <iostream>
#include <iterator>

#include "../../../../utils/functions/Functions.cpp" 

using namespace std;
using namespace toolkit;

/* Ref: Adapted from https://www.geeksforgeeks.org/random-access-iterators-in-cpp/ 
 */
int main() {
  vector<int> v1 = { 10, 20, 30, 40, 50 };

  cout << "Vector: "; printVector(v1); cout << endl;

  // using the subscript operator []
  int i = 2;
  cout << "Element #" << i << " = " << v1[i] << endl;

  // Declaring an iterator
  vector<int>::iterator i1;

  cout << "Replaced by: ";
  for (i1 = v1.begin(); i1 != v1.end(); ++i1) {
      // Assigning values to locations pointed by iterator
      *i1 = 7;
  }

  for (i1 = v1.begin(); i1 != v1.end(); ++i1) {
      // Accessing values at locations pointed by iterator
      cout << (*i1) << " ";
  }
  cout << endl;

  return 0;
}