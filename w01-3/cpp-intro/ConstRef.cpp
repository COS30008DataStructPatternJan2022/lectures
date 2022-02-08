#include "iostream"

using namespace std;

void constPointers() {
  cout << "constPointers()" << endl;
  int bufferSize = 512;
  const int& fixedBufferSize = bufferSize;

  cout << "bufferSize: " << bufferSize << ", fixedBufferSize: " << fixedBufferSize << endl;

  bufferSize = 1024;  // ok
  //error: fixedBufferSize = 1024;
  cout << "bufferSize: " << bufferSize << ", fixedBufferSize: " << fixedBufferSize << endl;

}

// default: call by value
void assign(int param, int val) {
  param = val;
}

// call by reference
void assignRef(int& param, int val) {
  param = val;
}

// call by reference but read-only
void assignConstRef(const int& param, int val) {
  // error:
  // param = val;
}

int main() {
  constPointers();

  int val = 10;
  cout << "Before: val = " << val << endl;
  assign(val, 3);
  cout << "After Assign(val, 3): val = " << val << endl;

  assignRef(val, 3);
  cout << "After AssignRef(val, 3): val = " << val << endl;

  assignConstRef(val, 3);
  cout << "After AssignConstRef(val, 3): val = " << val << endl;
  return 0;
}