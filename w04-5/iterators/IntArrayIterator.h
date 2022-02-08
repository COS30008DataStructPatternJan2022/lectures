class IntArrayIterator {
  private:
    const int* fArrayElements;
    const int fLength;
    int fIndex;

  public:
    // constructor
    IntArrayIterator(const int aArray[], const int aLength, int aStart = 0);

    const int& operator*() const;

    // prefix
    IntArrayIterator& operator++(); 
    // postfix (extra unused argument)
    IntArrayIterator operator++(int ); 
    // equivalence (equal check)
    bool operator==(const IntArrayIterator& aOther) const;
    // unequal check
    bool operator!=(const IntArrayIterator& aOther) const;
    // move first
    IntArrayIterator begin() const;
    // move last
    IntArrayIterator end() const;
};