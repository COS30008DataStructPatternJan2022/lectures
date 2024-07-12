/* 
  Diff: use a reference-type member (fList)
 */
template <typename T>
class SinglyLinkedListIterator {
  private:
    using ListNode = SinglyLinkedList<T>;
    // read-only reference to list elements
    // change: fList is a REFERENCE
    const ListNode& fList;
    const ListNode* fIndex;

  public:
    using Iterator = SinglyLinkedListIterator<T>;

    // constructor
    // change: aList is a reference
    SinglyLinkedListIterator(const ListNode& aList) : 
      fList(aList), // fList MUST be initialised here (before body code)
      fIndex(&aList)  // fIndex is a pointer: &aList = pointer to ListNode
    {
    }

    const T& operator*() const {
      return fIndex->fData;
    }

    /* prefix */
    Iterator& operator++() {
      fIndex = fIndex->fNext;
      return *this;
    }

    /* postfix */
    Iterator operator++(int) {
      Iterator old = *this;
      ++(*this);
      return old;
    }

    /* equality checks */
    bool operator==(const Iterator& aRHS) {
      // change: compare pointers
      return &fList == &aRHS.fList && 
        fIndex == aRHS.fIndex;
    }

    bool operator!=(const Iterator& aRHS) {
      return !(*this == aRHS);
    }

    /* for-range feature */
    Iterator begin() {
      Iterator iter = *this;
      // change: use pointers
      iter.fIndex = &iter.fList;
      return iter;
    }

    /* for-range feature */
    Iterator end() {
      Iterator iter = *this;
      iter.fIndex = nullptr;
      return iter;
    }
};