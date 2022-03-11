#include "iostream"
#include "memory"

using namespace std;

/**
 * Reference: Lippman et al, Section 12.1
 * - Adapted from the code in this section
 */

void printPtr(const string& name, shared_ptr<int>& p);

int main() {
  // conventional code
  /* int * p = new int();
  *p = 42; */

  shared_ptr<int> p = make_shared<int>(42); // object to which p points has one user
  printPtr("p", p);
  cout << endl;
  
  auto q(p); // p and q point to the same object
  // object to which p and q point has two users

  printPtr("p", p);
  printPtr("q", q);
  cout << endl;

  // p points to another object
  p = make_shared<int>(50);
  printPtr("p", p);
  printPtr("q", q);
  cout << endl;

  // r points to same object as q
  auto r(q);
  printPtr("r", r);
  cout << endl;

  // q points to another object
  q = make_shared<int>(100);
  printPtr("p", p);
  printPtr("q", q);
  printPtr("r", r);

  return 0;
}

void printPtr(const string& name, shared_ptr<int>& p) {
  cout << name + ": " << p 
    << " -> " << *p 
    << "; ref. count: " << p.use_count() << endl;
}