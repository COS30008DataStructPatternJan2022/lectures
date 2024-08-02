// #include "SortedList.h"
#include "iostream"
#include "list"

#include "config.h"

using namespace std;

/**
 * @brief PriorityQueue is an adapter container that captures a sorted list of elements. The elements can be of any type whose objects can be ordered (using the operator `<`). This includes primitive types (e.g. int, long, etc.) as well as value pairs (e.g. (1,2), (3,5), etc.).
 * 
 * The assumed sorting is ascending. 
 * 
 * @tparam T element type
 */
template<class T>
class PriorityQueue {
private:
  list<T> fElements;

public:
  PriorityQueue() {
    fElements = {};
  }
  
  ~PriorityQueue() {
    // delete fElements;
  }

  bool isEmpty() const {
    return fElements.empty();
  }
  
  size_t size() const {
    return fElements.size();
  }
  
 // insert element at the suitable position (determined based on sorting)
  void enqueue( const T& aItem ) {
    // insert aItem at the suitable position 
    if (debug) cout << "enqueue(" << aItem << ")" << endl;
    if (isEmpty()) {
        fElements.push_back(aItem);
        if (debug) cout << "  first-element: " << top() << endl;
    } else {
      bool inserted = false;
      auto it = fElements.begin();
      // loop using iterator to get access to the position for insertion
      for (it = fElements.begin(); it != fElements.end(); it++) {
        auto currElement = *it;
        if (debug) cout << "  currElement: " << currElement << endl;
        if (aItem < currElement) {
          break;
        }
      } 

      if (it != fElements.end()) {
        // found a position
        if (debug) cout << "-- inserted" << endl;
        fElements.insert(it, aItem);
      } else {
        // aItem is largest -> add to end
        if (debug) cout << "-- pushed_back" << endl;
        fElements.push_back(aItem);
      }
    }
  }
  
 // insert element at the suitable position (determined based on sorting)
  void enqueue(T&& aItem ) {
    if (debug) cout << "enqueue(" << std::move(aItem) << ")" << endl;
    if (isEmpty()) {
        fElements.push_back(std::move(aItem));
        if (debug) cout << "  first-element: " << top() << endl;
    } else {
      bool inserted = false;
      auto it = fElements.begin();
      // find the position
      for (it = fElements.begin(); it != fElements.end(); it++) {
        auto currElement = *it;
        if (debug) cout << "  currElement: " << currElement << endl;
        if (aItem < currElement) {
          break;
        }
      } 

      if (it != fElements.end()) {
        // found a position
        if (debug) cout << "-- inserted" << endl;
        fElements.insert(it, std::move(aItem));
      } else {
        // aItem is largest -> add to end
        if (debug) cout << "-- pushed_back" << endl;
        fElements.push_back(std::move(aItem));
      }
    }
  }

  // remove element at end
  void dequeue() {
    if (!isEmpty()) {
      fElements.pop_back();
    } else {
      throw std::underflow_error("Queue empty.");
    }
  }
    
  // access element at front of queue (i.e. fElements.end())
	const T& top() const {
    if (!isEmpty()) {
      return fElements.back();
    } else {
      throw std::underflow_error("Queue empty.");
    }
  }
};
