1. Contructor `IntArrayIndexer(const int aArray[], const int aLength)`: `const int aArray[]` is the same as `const int* aArray`, which is a pointer to the first array element. This conversion is performed automatically.
2. Explain the for loop in the implementation of operator `[]`
3. How to improve `IntArrayIndexers` to allow a client program to:
  - obtain all the keys as strings
  - operator `[]` does not need to convert key to number