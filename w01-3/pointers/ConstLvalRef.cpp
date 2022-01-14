#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

// using "const lvalue (object) reference"
void doString(const string &str) {
  cout << "doString()" << endl;
  cout << str << endl;

  // str = "";  // error: cannot change str
}

// using pointer type
void doString2(string * str) {
  cout << "doString2()" << endl;
  string val(*str);

  cout << "str: " << val << endl;

  *str = "world";
}

// using const pointer type
// void doString3(const string * str) {
//   cout << "doString3()" << endl;
//   string val = *str;
//   printf("str: %s \n", val);

//   // error: cannot modify
//   // *str = "world";
// }

int main() {
  string str = "hello";

  doString(str);

  doString2(&str);

  cout << "str: " << str << endl;

  // doString3(&str);

  return 0;
}