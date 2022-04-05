#include <iostream>
#include "BubbleSort.cpp"
#include "SelectionSort.cpp"

using namespace std;

#include "../../../utils/functions/Functions.cpp"

int main() {
  int arr[] = {3, 2,-1,3,-10,7};
  int length = sizeof(arr) / sizeof(int);

  cout << "Bubble sort" << endl;
  toolkit::printArr(arr, length);
  sortBubble(arr, length);
  toolkit::printArr(arr, length);

  cout << endl << "Selection sort" << endl;
  int  arr2[] = {3, 2,-1,3,-10,7};
  toolkit::printArr(arr2, length);
  sortSelection(arr2, length);
  toolkit::printArr(arr2, length);
}