#include "BNode.h"
#include "../visitors/TreeVisitor.h"

template<typename T>
class BinarySearchTree {
private: 
  BNode<T>* fRoot;

public: 
  BinarySearchTree() : fRoot(&BNode<T>::NIL) {}
  virtual ~BinarySearchTree() {  // destructor
    // delete fRoot;
  }

  bool empty() const {
    return fRoot->empty();
  }

  size_t height() const {
    throw std::domain_error("Not Yet Implemented!");
  }

  /* store aKey into this */
  bool insert(const T& aKey) {
    if (empty()) {
      fRoot = new BNode<T>(aKey);
      return true;  // insert succeeded
    } else {
      return fRoot->insert(aKey);
    }
  }

  bool remove(const T& aKey) {
    return fRoot->remove(aKey, &BNode<T>::NIL);
  }

  void traverseDepthFirst( const TreeVisitor<T>& aVisitor) const {
    return fRoot->traverseDepthFirst(aVisitor);
  }
};