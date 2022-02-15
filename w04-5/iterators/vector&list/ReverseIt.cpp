#include <vector>
#include <iostream>

#include "../../../../utils/functions/Functions.cpp"

using namespace std;
using namespace toolkit;

/* Ref: Lippman et al, Section 10.4.3
  @overview Reverse iterator
 */

int main() {
  vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << "Vector: " << endl;
  printIntVector(vec);
  cout << "Reverse print: " << endl;
  // reverse iterator of vector from back to front
  for (auto r_iter = vec.crbegin(); // binds r_iter to the last element
    r_iter != vec.crend();       // crend refers 1 before 1st element
    ++r_iter)                    // decrements the iterator one element
  {
    cout << *r_iter << endl;        // prints 9, 8, 7, . . . 0
  }
}