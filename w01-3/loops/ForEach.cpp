#include <iostream>

using namespace std;

int main() {
  int a[] = {1,2,3,4,17};
  cout << "for-each#1" << endl;
  for (int i : a) { // hex << &i returns SAME value
    cout << "("<< hex << &i << dec << ", " << sizeof(i) << "): " << i << endl;
  }

  cout << "for-each#2" << endl;
  // Recommended!
  for (const int& i : a) {  // hex << &i returns DIFFERENT values
    cout << "("<< hex << &i <<  dec << ", " << sizeof(i) << "): " << i << endl;
  }

  cout << "for-each#3" << endl;
  for (auto i : a) { // hex << &i returns SAME value (and same as for-each#1)
    cout << "("<< hex << &i << dec << ", " << sizeof(i) << "): " << i << endl;
  }  

  // Recommended (better)!
  cout << "for-each#4" << endl;
  for (const auto& i : a) {  // hex << &i returns DIFFERENT values, but pair-wise the same as for-each#2
    cout << "(" << hex << &i <<  dec << ", " << sizeof(i) << "): " << i << endl;
  }  
}