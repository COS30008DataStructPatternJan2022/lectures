/* URL: https://docs.microsoft.com/en-us/cpp/standard-library/list-class
 */
#include <list>
#include <iostream>
#include <string>

#include "../../../utils/functions/Functions.cpp"

using namespace std;

void assign()
{
  list<int> c1, c2;
  list<int>::const_iterator cIter;

  c1.push_back(10);
  c1.push_back(20);
  c1.push_back(30);
  c2.push_back(40);
  c2.push_back(50);
  c2.push_back(60);

  cout << "c1 =";
  for (auto c : c1)
    cout << " " << c;
  cout << endl;

  c1.assign(++c2.begin(), c2.end());
  cout << "c1 =";
  for (auto c : c1)
    cout << " " << c;
  cout << endl;

  c1.assign(7, 4);
  cout << "c1 =";
  for (auto c : c1)
    cout << " " << c;
  cout << endl;

  c1.assign({10, 20, 30, 40});
  cout << "c1 =";
  for (auto c : c1)
    cout << " " << c;
  cout << endl;
}

void insert()
{
  list<int> c1, c2;
  list<int>::iterator Iter;

  c1.push_back(10);
  c1.push_back(20);
  c1.push_back(30);
  c2.push_back(40);
  c2.push_back(50);
  c2.push_back(60);

  cout << "c1 =";
  for (auto c : c1)
    cout << " " << c;
  cout << endl;

  Iter = c1.begin();
  Iter++;
  c1.insert(Iter, 100);
  cout << "c1 =";
  for (auto c : c1)
    cout << " " << c;
  cout << endl;

  Iter = c1.begin();
  Iter++;
  Iter++;
  c1.insert(Iter, 2, 200);

  cout << "c1 =";
  for (auto c : c1)
    cout << " " << c;
  cout << endl;

  c1.insert(++c1.begin(), c2.begin(), --c2.end());

  cout << "c1 =";
  for (auto c : c1)
    cout << " " << c;
  cout << endl;

  // initialize a list of strings by moving
  list<string> c3;
  string str("a");

  c3.insert(c3.begin(), move(str));
  cout << "Moved first element: " << c3.front() << endl;

  // Assign with an initializer_list
  list<int> c4{{1, 2, 3, 4}};
  c4.insert(c4.begin(), {5, 6, 7, 8});

  cout << "c4 =";
  for (auto c : c4)
    cout << " " << c;
  cout << endl;
}

void loopByIterator() {
  /* URL: https://home.csulb.edu/~pnguyen/cecs282/lecnotes/iterators.docx */

  using namespace toolkit;

  list<int> elements;
  elements.assign({1,2,3});
  cout << "list:" << endl;
  printList(elements);

  // read-loop using iterator
  for (list<int>::iterator it = elements.begin(); it != elements.end(); it++) {
    cout << *it << endl;  // *it: deference it to get the value
  }

  // update-loop using iterator
  int e = 2;
  int insertElement = 100;
  // ALT:  can replace 'list<int>::iterator' by 'auto' in c++11
  for (list<int>::iterator it = elements.begin(); it != elements.end(); it++) {
    // insert an element into a position using iterator
    int ce = *it;
    cout << "ce: " << ce << endl;
    if (ce == e) {
      elements.insert(it, insertElement);
      cout << "--> inserted: " << insertElement << endl;
    }
  }

  cout << "updated list:" << endl;
  printList(elements);
}

int main()
{
  // cout << "assign()" << endl;
  // assign();

  // cout << "insert()" << endl;
  // insert();

  loopByIterator();
}