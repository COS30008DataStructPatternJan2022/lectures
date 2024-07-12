template <typename T>
class SinglyLinkedListIterator {
  private:
    using ListNode = SinglyLinkedList<T>;
    // read-only POINTER to list elements
    const ListNode* fList;
    // read-only pointer to current List node
    const ListNode* fIndex;

  public:
    using Iterator = SinglyLinkedListIterator<T>;

    // constructor
    SinglyLinkedListIterator(const ListNode* aList) : 
      fList(aList),
      fIndex(aList)
    {}

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
      return fList == aRHS.fList && 
        fIndex == aRHS.fIndex;
    }
    bool operator!=(const Iterator& aRHS) {
      return !(*this == aRHS);
    }

    /* for-range feature */
    Iterator begin() {
      Iterator iter = *this;
      iter.fIndex = iter.fList;
      return iter;
    }

    /* for-range feature */
    Iterator end() {
      Iterator iter = *this;
      iter.fIndex = nullptr;
      return iter;
    }
};