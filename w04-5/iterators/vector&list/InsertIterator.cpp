#include <list>
#include <iterator>
#include <iostream>

using namespace std;

/* Ref: Lippman et al, Section 10.4.1
  Insert Iterators
 */

void printList(const list<int>& list) {
  // Adapted from: https://stackoverflow.com/a/16229897
  std::copy(list.cbegin(), 
    list.cend(), 
    std::ostream_iterator<int>(std::cout, " "));
}

int main() {
  list<int> lst = {1,2,3,4};
  cout << "List: "; printList(lst); cout << endl;

  list<int> lst2, lst3; // empty lists

  // after copy completes, lst2 contains 4 3 2 1
  copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
  cout << "List2: "; printList(lst2); cout << endl;
  // after copy completes, lst3 contains 1 2 3 4
  copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
  cout << "List3: "; printList(lst3); cout << endl;
}