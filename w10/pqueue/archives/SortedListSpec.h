#include "../../../labs/w07/DoublyLinkedList.h"
#include "../../../labs/w07/DoublyLinkedListIterator.h"
#include <stdexcept>

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
  SortedList();
  // copy constructor
  SortedList(const SortedList& aOtherList);
  // move constructor
  SortedList( SortedList&& aOtherList);
  // assignment operator
  SortedList& operator=(const SortedList& aOtherList);
  // move assignment operator
  SortedList& operator=(SortedList&& aOtherList);
  // deconstructor (free all nodes)
  ~SortedList();

  bool isEmpty() const;
  int size() const;

  // adds element at a proper position
  void insert( const T& aElement);
  // adds element at a proper position
  void insert( const T&& aElement);
  // removes first match from list
  void remove( const T& aElement);

  // list indexer
  const T& operator[]( size_t aIndex ) const;

  // forward iterator
  Iterator begin() const;
  // forward end iterator
  Iterator end() const;
  // backward iterator
  Iterator rbegin() const;
  // backward end iterator
  Iterator rend() const;
};
