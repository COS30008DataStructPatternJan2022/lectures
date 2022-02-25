#include <iostream>
using namespace std;

/* returns the greatest common divisor (gcd) of two integral numbers
   @post
    result = r s.t. r = max({d | x % d = 0 and y % d = 0})
 */
long gcd(long x, long y) {
  if (y == 0) { 
    return x; // tail-recursion
  } else {
    return gcd(y, x % y);
  }
}

int main() {
  long xs[] = {1246, 42, 34, 56, 15}; 
  long ys[] = {234, 3, 4, 5, 3};

  for (long& x : xs) {
    for (long& y : ys) {
        cout << "gcd("<< x <<","<< y << ") = " << gcd(x,y) 
        << "; gcd("<< y <<","<< x << ") = " << gcd(y,x) 
        << endl; 
    }
  }
}