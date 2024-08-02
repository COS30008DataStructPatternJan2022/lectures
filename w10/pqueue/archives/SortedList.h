#include "../../../labs/w07/DoublyLinkedList.h"
#include "../../../labs/w07/DoublyLinkedListIterator.h"
#include <stdexcept>
#include "iostream"

using namespace std;

template<class T>
class SortedList {
private:
  // auxiliary definition to simplify node usage
  using Node = DoublyLinkedList<T>;
  Node* fRoot;  // first element in the list
  int fCount; // number of elements

public:
  // auxiliary definition to simplify iterator usage
  using Iterator = DoublyLinkedListIterator<T>;

  // default constructor
  SortedList() {
    // todo
    cout << "Not-Yet-Implemented";
  }
  // copy constructor
  SortedList(const SortedList& aOtherList) {
    // todo
    cout << "Not-Yet-Implemented";
  }
  // move constructor
  SortedList( SortedList&& aOtherList)  {
    // todo
    cout << "Not-Yet-Implemented";
  }
  // assignment operator
  SortedList& operator=(const SortedList& aOtherList)  {
    // todo
    cout << "Not-Yet-Implemented";
  }
  // move assignment operator
  SortedList& operator=(SortedList&& aOtherList);
  // deconstructor (free all nodes)
  ~SortedList() {
    // todo
    cout << "Not-Yet-Implemented";
  }

  bool isEmpty() const {
    return fCount == 0;
  }

  int size() const {
    return fCount;
  }

  /** 
   * adds element at a proper position
   * @pseudocode: implements algorithm given in Preiss's book ("Inserting items in a Sorted List")
   */
  void insert( const T& aElement) {
    const Node* prevPtr = 0; // previous element
    const Node* ptr = fRoot;     // current element

    Node newNode = Node(aElement);

    while (ptr != 0 && ptr < newNode) {
      // current element < aElement: continue to move forward
      // to search the the first element that is larger
      prevPtr = ptr;
      ptr = ptr->getNext();
    }

    if (prevPtr == 0) {
      // aElement is smaller than the first element, insert at the front
      fRoot->push_front(newNode);
    } else {
      // insert aElement after prevPtr's
      prevPtr->push_back(newNode);
    }
  }

  // adds element at a proper position
  void insert( const T&& aElement) {
    // todo
    cout << "Not-Yet-Implemented";
  }

  // removes first match from list
  void remove( const T& aElement) {
    Node* prevPtr = 0; // previous element
    const Node* ptr = fRoot; // current element

    while (ptr != 0 && ptr->getPayload() != aElement) {
      prevPtr = ptr;
      ptr = ptr->getNext();
    }

    if (prevPtr == 0) {
      // aElement is not in this list: do nothing
    } else {
      // remove aElement by isolating its node
      prevPtr->isolate();
    }
  }

  // list indexer
  const T& operator[]( size_t aIndex ) const {
    if (isEmpty()) {
      return 0;
    }

    const Node* prevPtr = 0; // previous element
    const Node* ptr = fRoot; // current element

    size_t ind = 0;
    do {
      prevPtr = ptr;
      ptr = ptr->getNext();
      ind++;
    } while (ptr != 0 && ind < aIndex);

    return prevPtr->getPayload();
  }

  // forward iterator
  Iterator begin() const {
    // todo
    cout << "Not-Yet-Implemented";
  }
  // forward end iterator
  Iterator end() const {
    // todo
    cout << "Not-Yet-Implemented";
  }
  // backward iterator
  Iterator rbegin() const {
    // todo
    cout << "Not-Yet-Implemented";
  }
  // backward end iterator
  Iterator rend() const {
    // todo
    cout << "Not-Yet-Implemented";
  }
};
