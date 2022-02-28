#include <iostream>

using namespace std;

/* post: compute and return the Fibonacci f(n) */
long fib (unsigned long n) {
  if (n <= 2) { // f(1), f(2)
    return 1;
  } else {  // f(n) = f(n-1) + f(n-2)
    return fib(n-1) + fib(n-2);  // recursion
  }
}

// rewritten using tail-recursion
long tailFib (unsigned long n, unsigned long f1, unsigned long f2) {
  if (n <= 2) {
    return f2;
  } else {
    unsigned long temp = f1;
    f1 = f2;
    f2 = temp + f2;
    return tailFib(n-1, f1, f2);  // tail recursion
  }
}

int main() {
  int n = 6;
  cout << "fib("<< n << ") = " << fib(n) << endl;

  unsigned long result = tailFib(n, 1, 1);
  cout << "tailFib("<< n << ") = " << result << endl;

  return 0;
}