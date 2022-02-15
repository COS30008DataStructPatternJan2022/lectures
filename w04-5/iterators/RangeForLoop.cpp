#include <iostream>

using namespace std;
/* Lippman et al: Section 17.5.1/Specifying the base for integral values */
int main() {

  int a[] = {1,2,3,4,17};
  cout << "for-each#1: copy" << endl;
  // copy values
  for (int i : a) { 
    cout << i << endl;
  }

  cout << "for-each#2 (recommended without auto)" << endl;
  // Recommended! (using value references instead of copies & not changing original element)
  for (const int& i : a) { 
    cout << i << endl;
  }

  /* use this loop to change a through i
  for (int& i : a) { 
    i = 3;
  }
  */

  // using auto (but still copies)
  cout << "for-each#3: copy with auto" << endl;
  for (auto i : a) { 
    cout << i << endl;
  }  

  // Recommended (better)!: auto + reference
  cout << "for-each#4: recommended (with auto)" << endl;
  for (const auto& i : a) { 
    cout << i << endl;
  }  
}