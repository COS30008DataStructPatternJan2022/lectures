#include "iostream"
#include "list"

using namespace std;

template<class T>
class Queue {
private:
  list<T> fElements;

public:
  Queue() {
    fElements = {};
  }
  
  ~Queue() {
    // todo: delete fElements;
  }

  bool isEmpty() const {
    return fElements.size() == 0;
  }
  
  size_t size() const {
    return fElements.size();
  }
  
  // insert element at the end
  void enqueue( const T& aItem ) {
    fElements.push_back(aItem);
  }
  
  // insert element at the end
  void enqueue( T&& aItem ) {
    fElements.push_back(std::move(aItem));
  }

  // remove element at end
  void dequeue() {
    if (!isEmpty()) {
      fElements.pop_front();
      // fElements.remove(fElements[0]);
    } else {
      throw std::underflow_error("Queue empty.");
    }
  }
    
  // access element at front
	const T& top() const {
    if (!isEmpty()) {
      // return fElements[0];
      return *fElements.begin();
    } else {
      throw std::underflow_error("Queue empty.");
    }
  }
};
