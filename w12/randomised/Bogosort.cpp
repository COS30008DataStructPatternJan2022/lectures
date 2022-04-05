#include <iostream>

#include "../../../utils/functions/Functions.cpp"

// by Fisher&Yates
void shuffle(int * aArray, int aLength) {
  int n = aLength;
  while ( n > 1 ) {
      // new random index in the range 0 to n
      int k = rand() % n;
      n--;    // n last pertinent index
      toolkit::swap(aArray, n, k);
  }
}

void sortByFisherAndYates(int * aArray, int aLength) {
  bool isSorted;

  do {
    isSorted = true;
    for (int i = 0; isSorted && i < aLength-1; i++) {
      if (aArray[i] < aArray[i+1]) {  // sort descending
        isSorted = false;
      }

      if (!isSorted) {
        // randomised!
        shuffle(aArray, aLength);
      }
    }
  } while (!isSorted);
}
