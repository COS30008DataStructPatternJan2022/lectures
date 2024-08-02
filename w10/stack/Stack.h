#include "iostream"
using namespace std;

// template<typename T>
template<class T>
class Stack {
private:
  T* fElements;
  size_t fStackPointer;
  size_t fStackSize;

public:
  Stack(size_t aSize) {
    fStackSize = aSize;
    fElements = new T[fStackSize];
    fStackPointer = 0;
  }
  
  ~Stack() {
    delete [] fElements;
  }

  bool isEmpty() const {
    return fStackPointer == 0;
  }
  
  size_t size() const {
    return fStackPointer;
  }
  
  void push( const T& aItem ) {
    if (fStackPointer < fStackSize) {
      fElements[fStackPointer++] = aItem;
    } else {
      throw std::overflow_error("Stack full.");
    }
  }
  
  void push( T&& aItem ) {
    if (fStackPointer < fStackSize) {
      fElements[fStackPointer++] = std::move(aItem);
    } else {
      throw std::overflow_error("Stack full.");
    }
  }

  void pop() {
    if (!isEmpty()) {
      fStackPointer--;
    } else {
      throw std::underflow_error("Stack empty.");
    }
  }
    
	const T& top() const {
    if (!isEmpty()) {
      return fElements[fStackPointer-1];
    } else {
      throw std::underflow_error("Stack empty.");
    }
  }
};
