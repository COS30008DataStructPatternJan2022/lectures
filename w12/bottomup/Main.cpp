#include <iostream>
#include "Fibonacci.cpp"

using namespace std;

int main() {
  int n = 8;

  int f = iterFibo(n);

  cout << "iterFibo(" << n << ") = " << f << endl;
}