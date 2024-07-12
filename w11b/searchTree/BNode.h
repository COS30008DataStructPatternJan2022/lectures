#include <stdexcept>
#include "../visitors/TreeVisitor.h"

#include "iostream"

template<typename S>
struct BNode {
  S key;            // key value of this node
  BNode<S>* left;   // root of left tree
  BNode<S>* right;  // root of right tree

  virtual ~BNode() {
    // delete left;
    // delete right;
  }

  static BNode<S> NIL;
  // other members

  // constructor
  BNode() : key(S()),
            left(&NIL),
            right(&NIL){
    //
  }
  BNode(S aKey) : key(aKey),
            left(&NIL),
            right(&NIL) {

  }

  bool empty() const {
    return this == &NIL;
  }

  /* store aKey into this */
  bool insert(const S& aKey) {
    BNode<S>* x = this;
    BNode<S>* t = &BNode<S>::NIL; // t: target

    // look for the suitable subtree (y) where aKey is stored
    while (!x->empty()) {
      t = x;
      if (aKey == x->key) {
        return false;       // insert failed: duplicate key
      }
      x = (aKey < x->key) ? x->left : x->right;
    }

    /* x = NIL /\ t = x.parent /\ 
       aKey != t.aKey /\ 
       (t.left = NIL -> aKey < t.aKey) /\ 
       (y.right = NIL -> aKey > t.aKey)
     */

    // initialise a node for aKey
    BNode<S>* z = new BNode<S>(aKey);
    if (t->empty()) { // this is NIL
      return false;   // insert failed (NIL)
    } else {  // insert z as a child of y
      if (aKey < t->key) {
        t->left = z;
      } else {
        t->right = z;
      }
    }

    return true;  // insert succeeded
  }

  /* remove aKey from a subtree, starting with aParent */
  bool remove(const S& aKey, BNode<S>* aParent) {
    BNode<S>* t = this;  // t: target subtree where t.key = aKey
    BNode<S>* y = aParent;

    while (!t->empty()) {
      if (aKey == t->key) { // (found it) aKey is in this
        break;
      }

      y = t;  // new parent
      t = (aKey < t->key) ? t->left : t->right;
    }

    if (t->empty()) return false;    // delete failed

    /* assert: 
      aKey = t.key /\ y = t.parent
    */
    if (!t->left->empty()) {  // t is not leaf
      const S& lKey = t->left->findMax(); // find max to left
      t->key = lKey;          // replace t->key by lKey (effectively removing aKey)
      t->left->remove(lKey, t); // remove lKey (recursively)
    } else {  // t is leaf -> remove t
      if (y->left == t) { // y.left = t
        y->left = &NIL;
      } else {  // y.right = t
        y->right = &NIL;
      }

      delete t;
    }

    return true;  // delete succeeded
  }

  /* find and return the max key in this */
  S findMax() {
    S max = key;
    if (!left->empty()) { // search left subtree
      max = std::max(max, left->findMax());
    }
    if (!right->empty()) {  // search right subtree
      max = std::max(max, right->findMax());
    }
    return max;
  }

  void traverseDepthFirst(const TreeVisitor<S>& aVisitor) const {
    if (!empty()) {
      aVisitor.visit(key);
      left->traverseDepthFirst(aVisitor);
      right->traverseDepthFirst(aVisitor);
    }
  }
};

template<typename S>
BNode<S> BNode<S>::NIL;