// Reference: https://docs.microsoft.com/en-us/cpp/cpp/enumerations-cpp?view=msvc-160

#include "iostream"
using namespace std;

int main() {
  int ivar = 3;
  printf("ivar = %d\n", ivar);

  int* pivar = &ivar;
  printf("pivar = %p\n", pivar);

  float fvar = 3.14;
  printf("fvar = %f\n", fvar);
  printf("(formatted) fvar = %.2f\n", fvar);

  float* pfvar = &fvar;
  printf("pfvar = %p\n", pfvar);

  // formatted line
  string header = "%5s%10s\n";
  string row = "%5d%10.2f\n";
  printf(header.c_str(), "ivar|", "fvar|");
  printf(row.c_str(), ivar, fvar);

  return 0;
}