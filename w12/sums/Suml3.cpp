/* result = sum_{i=1..n} i^3 */
int sum(int n) {
  int sum = 0;

  for (int i = 1; i <= n; i++) {
    sum += i * i * i;
  }

  return sum;
}