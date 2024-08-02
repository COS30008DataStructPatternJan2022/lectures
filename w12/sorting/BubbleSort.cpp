#include "../../../utils/functions/Functions.cpp"

void sortBubble(int aArray[], int aLength) {
  for (unsigned int i = aLength-1; i > 0 ; i--) {
    for (int j = 0; j < i ; j++) {
      if (aArray[j+1] < aArray[j]) {
        toolkit::swap(aArray, j+1, j);
      }
    }
  }
}
