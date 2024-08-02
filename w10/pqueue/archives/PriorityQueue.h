#include "SortedList.h"

template<class T>
class PriorityQueue {
private:
  SortedList<T> fElements;

public:
  PriorityQueue() {
    fElements = {};
  }
  
  ~PriorityQueue() {
    // delete fElements;
  }

  bool isEmpty() const {
    return fElements.size() == 0;
  }
  
  size_t size() const {
    return fElements.size();
  }
  
  // insert element 
  void enqueue( const T& aItem ) {
    fElements.insert(aItem);
  }
  
  // insert element
  void enqueue( T&& aItem ) {
    fElements.insert(std::move(aItem));
  }

  // remove element at end
  void dequeue() {
    if (!isEmpty()) {
      fElements.remove(fElements[size() - 1]);
    } else {
      throw std::underflow_error("Queue empty.");
    }
  }
    
  // access element at front
	const T& top() const {
    if (!isEmpty()) {
      return fElements[size() - 1];
    } else {
      throw std::underflow_error("Queue empty.");
    }
  }
};
