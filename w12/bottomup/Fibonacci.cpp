
long iterFibo(long n) {
  long prev = 1;
  long curr = 0;
  for (long i = 1; i <= n; i++) {
    long next = curr + prev;
    prev = curr;
    curr = next;
  }

  return curr;
}