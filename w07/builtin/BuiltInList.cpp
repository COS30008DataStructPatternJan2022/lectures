/* 
  std::list: https://www.cplusplus.com/reference/list/list/
 */
#include <iostream>
#include <list>

using namespace std;

/* 
Define a template function.
post: print to the standard output elements of lst one by one on the same line 
*/
template <typename T> void printList(list<T>& lst) {
  cout << "List: ";
  for (const T& i : lst) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  list<int> lst = {1,2,3,4,5};  // similar to array initialisation
  printList(lst);

  // accessor operations
  printf(" Size: %d\n First: %d\n Last: %d\n", 
    (int)lst.size(), 
    lst.front(),
    lst.back()
    );

  // modification
  list<int>::iterator it = lst.begin();

  // add to back
  for (int i = 6; i <= 10; i++) lst.push_back(i);
  printList(lst);

  // add to front
  lst.push_front(200);
  printList(lst);

  // // insert
  // lst.insert(it,1,100);
  // printList(lst);

  // // erase elements
  // // it still points to 1 (first list)
  // lst.erase(it);
  // printList(lst);

  // // update it to new list
  // it = lst.begin();
  // it = lst.erase(it);
  // printList(lst);

  // lst.erase(it);
  // printList(lst);

  return 0;
}