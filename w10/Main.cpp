#include "iostream"
// #include "NTree.h"
#include "NTreeError.h"

using namespace std;

int main() {
  using NS3Tree = NTree<string,3>;

  string s1("A");
  string s2("B");
  string s3("C");

  NS3Tree root("Hello world!");
  NS3Tree nodeA(s1);
  NS3Tree nodeB(s2);
  NS3Tree nodeC(s3);
  NS3Tree nodeAB("AB");

  root.attach(0, nodeA);
  root.attach(1, nodeB);
  root.attach(2, nodeC);

  const_cast<NS3Tree&>(root[1]).attach(1, nodeAB);

  cout << "root: " << *root << endl;
  cout << "root[0]: " << *root[0] << endl;
  cout << "root[1]: " << *root[1] << endl;
  cout << "root[2]: " << *root[2] << endl;
  cout << "root[1][1]: " << *root[1][1] << endl;

  // const_cast<NS3Tree&>(root[1]).detach(1);
  // root.detach(0);
  // root.detach(1);
  // root.detach(2);

  // this must be done after root.detach(0)!
  // root.attach(0, NS3Tree("new A"));
  // cout << "root[0]: " << *root[0] << endl;

  return 0;
}