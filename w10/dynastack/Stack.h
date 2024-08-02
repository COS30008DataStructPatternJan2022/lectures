#include "iostream"
#include <list>

using namespace std;

template<class T>
class Stack {
private:
  int fStackSize;
  list<T> fElements;

public:
  Stack(size_t aSize) {
    fStackSize = aSize;
    fElements = {};
  }
  
  ~Stack() {
    // todo: delete fElements;
  }

  bool isEmpty() const {
    return fElements.size() == 0;
  }
  
  size_t size() const {
    return fElements.size();
  }
  
  void push( const T& aItem ) {
    if (size() < fStackSize) {
      fElements.push_front(aItem);
    } else {
      throw std::overflow_error("Stack full.");
    }
  }
  
  void push( T&& aItem ) {
    if (size() < fStackSize) {
      fElements.push_front(std::move(aItem));
    } else {
      throw std::overflow_error("Stack full.");
    }
  }

  void pop() {
    if (!isEmpty()) {
      // List<T>::iterator it = fElements.begin();
      // fElements.erase(it);
      fElements.pop_front();
    } else {
      throw std::underflow_error("Stack empty.");
    }
  }
    
	const T& top() const {
    if (!isEmpty()) {
      return *fElements.begin();
    } else {
      throw std::underflow_error("Stack empty.");
    }
  }
};
