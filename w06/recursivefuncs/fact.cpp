#include <iostream>

using namespace std;

/* post: compute and return n! */
long factorial (unsigned long n) {
  if (n == 0) { // suggestion: change to n == 1
    return 1;
  } else {
    return n * factorial(n-1);  // recursion
  }
}

// rewritten using tail-recursion
void tailFactorial (unsigned long n, unsigned long& f) {
  if (n == 1) {
    // stop (return f)
  } else {  // f = (n-1)!
    f = n * f;  // n * (n-1)!
    return tailFactorial(n-1, f);  // // tail recursion
  }
}

int main() {
  int n = 6;
  cout << "factorial("<< n << ") = " << factorial(n) << endl;

  cout << "tailFactorial("<< n << ") = " << factorial(n) << endl;

  return 0;
}