#include <iostream>
using namespace std;

/* URL: https://www.cplusplus.com/doc/tutorial/pointers/ */
int main () {
  // array is the pointer to its 1st element!
  int numbers[5];
  int * p;
  p = numbers;  
  *p = 10;  // 1st element
  p++;  *p = 20;  // 2nd element
  p = &numbers[2];  *p = 30;  // 3rd element
  p = numbers + 3;  *p = 40;  // 4th element
  p = numbers;  *(p+4) = 50;  // 5th element
  for (int n=0; n<5; n++)
    cout << numbers[n] << ", ";

  cout << endl;
  
  return 0;
}