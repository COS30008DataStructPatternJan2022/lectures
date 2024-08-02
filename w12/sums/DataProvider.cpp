/* computes the max sum for a subsequence of values in the array 
  @return max subsequence sum in O(n3)
 */
int maxSubSumON3(const int& fEntryCount, int* fNumbers) {
  int lMaxSum = 0;
  for (int i = 0; i < fEntryCount; i++) {
    for (int j = i; j < fEntryCount; j++) {
      int lThisSum = 0;
      for (int k = i; k <= j; k++) {
        lThisSum += fNumbers[k];
      }

      if (lThisSum > lMaxSum) {
        lMaxSum = lThisSum;
      }
    }
  }

  return lMaxSum;
}

/* computes the max sum for a subsequence of values in the array 
  @return max subsequence sum in O(n)
 */
int maxSubSumON(const int& fEntryCount, int* fNumbers) {
  int lMaxSum = 0;
  int lThisSum = 0;

  for (int i = 0; i < fEntryCount; i++) {
    lThisSum += fNumbers[i];

    if (lThisSum > lMaxSum) {
      lMaxSum = lThisSum;
    } else {
      if (lThisSum < 0)
        lThisSum = 0;
    }
  }
  return lMaxSum;
}