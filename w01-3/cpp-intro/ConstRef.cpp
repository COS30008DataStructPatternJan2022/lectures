#include "iostream"

using namespace std;

// default: call by value
void Assign(int param, int val) {
  param = val;
}

// call by reference
void AssignRef(int& param, int val) {
  param = val;
}

// call by reference but read-only
void AssignConstRef(const int& param, int val) {
  // error:
  // param = val;
}

int main() {
  int val = 10;
  cout << "Before: val = " << val << endl;
  Assign(val, 3);
  cout << "After Assign(val, 3): val = " << val << endl;

  AssignRef(val, 3);
  cout << "After AssignRef(val, 3): val = " << val << endl;

  AssignConstRef(val, 3);
  cout << "After AssignConstRef(val, 3): val = " << val << endl;
  return 0;
}