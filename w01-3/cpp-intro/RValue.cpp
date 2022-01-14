
int main() {
  int var = 42;
  int& ref = var;
  // error: initial value of reference to non-const must be an lvalue
  // int& ref2 = 42;
  const int& ref3 = 42;
}