#include <iostream>
using namespace std;

void basicPointers() {
  cout << "basicPointers()" <<endl;

  int myVar = 25;
  auto foo = &myVar;  // pointer 
  auto val = *foo;    // dereference

  int * foo1 = &myVar;  // pointer (same as foo)

  // assert:
  cout << "myVar == 25: " << (myVar == 25) << endl;
  cout << "val == myVar: " << (val == myVar) << endl;

  *foo1 = 100;

  // assert:
  cout << "myVar == 25: " << (myVar == 25) << endl;
  cout << "myVar == 100: " << (myVar == 100) << endl;
  cout << "foo == foo1 " << "(" << foo1 << "): " << (foo == foo1) << endl;
}

void constPointers() {
  cout << "constPointers()" <<endl;

  int x;
  int y = 10;
  const int * p = &y; // p: constant pointer
  x = *p;          // ok: reading p's pointed value
  //*p = x;          // error: modifying p's pointed value, which is const-qualified
}

void increment_all (int* start, int* stop)
{
  cout << "increment_all()" <<endl;
  int * current = start;
  while (current != stop) {
    ++(*current);  // increment value pointed
    ++current;     // increment pointer
  }
}

void print_all (const int* start, const int* stop)
{
  cout << "print_all()" <<endl;
  const int * current = start;
  while (current != stop) {
    cout << *current << '\n';
    ++current;     // increment pointer
  }
}

void constPointers2() {
  cout << "constPointers2()" <<endl;

  int numbers[] = {10,20,30};
  increment_all (numbers,numbers+3);
  print_all (numbers,numbers+3);
}

/* URL: https://www.cplusplus.com/doc/tutorial/pointers/ */
int main() {

  basicPointers();

  constPointers();

  constPointers2();

  return 0;
}