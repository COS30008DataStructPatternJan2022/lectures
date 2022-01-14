/*
  References: 
  - printf: https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-160
  - IOStream alternatives: https://docs.microsoft.com/en-us/cpp/standard-library/input-output-alternatives?view=msvc-160
  - Using iostream: https://docs.microsoft.com/en-us/cpp/standard-library/using-cpp-library-headers?view=msvc-160
  - Using insertion operator (e.g. <<, >>) in streams: 
      url1: https://docs.microsoft.com/en-us/cpp/standard-library/using-insertion-operators-and-controlling-format?view=msvc-160
      url2: https://www.javatpoint.com/cpp-manipulator-hex-function
 */
#include <iostream>
using namespace std;

int main() {
  cout << "Enter two numbers: " << endl;
  int v1, v2;
  cin >> v1 >> v2;
  cout << "The sum of " << v1 << " and " << v2 << " is " << v1  + v2 << endl;
  cout.write("~End~\n", 10);
  return 0;
}