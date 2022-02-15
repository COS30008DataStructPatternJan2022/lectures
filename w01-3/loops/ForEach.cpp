#include <iostream>

using namespace std;

/* Lippman et al: Section 17.5.1/Specifying the base for integral values */
int main() {
  int n = 5;
  int& r = n;
  cout << "r (&n) = " << r << endl 
       << "&r = "  << &r << endl
       << "hex << &r = " << hex << &r << endl;

  int a[] = {1,2,3,4,17};
  cout << "for-each#1" << endl;
  // copy values
  for (int i : a) { // hex << &i returns SAME value for all i
    cout << "("<< &i << "," << hex << &i << dec << ", " << sizeof(i) << "): " << i << endl;
  }

  cout << "for-each#2" << endl;
  // Recommended! (using value references instead of copies)
  for (const int& i : a) {  // hex << &i returns a DIFFERENT value for each i
    cout << "("<< &i << "," << hex << &i <<  dec << ", " << sizeof(i) << "): " << i << endl;
  }

  // using auto (but still copies)
  cout << "for-each#3" << endl;
  for (auto i : a) { // output same as for-each#1
    cout << "("<< &i << "," << hex << &i << dec << ", " << sizeof(i) << "): " << i << endl;
  }  

  // Recommended (better)!: auto + reference
  cout << "for-each#4" << endl;
  for (const auto& i : a) {  // output same as for-each#2
    cout << "("<< &i << "," << hex << &i <<  dec << ", " << sizeof(i) << "): " << i << endl;
  }  
}