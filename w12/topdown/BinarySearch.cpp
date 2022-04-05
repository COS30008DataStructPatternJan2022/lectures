/**
  @requires: aSortedArray is sorted
  @effects: 
    if aSearchValue is in aSortedArray 
      return its position
    else 
      return -1
 */
int doBinarySearch(int aSortedArray[], int aLength, int aSearchValue) {
  int lLowerIndex = 0;  // leftmost index
  int lHighIndex = aLength - 1;  // rightmost index

  while (lLowerIndex < lHighIndex) {
    int lMidIndex = (lLowerIndex + lHighIndex) / 2;
    if (aSortedArray[lMidIndex] == aSearchValue) 
      return lMidIndex;   // found

    if (aSortedArray[lMidIndex] > aSearchValue) {
      lHighIndex = lMidIndex - 1;   // new rightmost index
    } else {
      lLowerIndex = lMidIndex + 1;  // new leftmost array index
    }

    return -1;    // element not found
  }
}