
#include "Bogosort.cpp"
#include "../../../utils/functions/Functions.cpp"

using namespace std;

int main() {
  int arr[] = {3, 2,-1,3,-10,7};
  int length = sizeof(arr) / sizeof(int);

  toolkit::printArr(arr, length);

  sortByFisherAndYates(arr, length);

  toolkit::printArr(arr, length);
}