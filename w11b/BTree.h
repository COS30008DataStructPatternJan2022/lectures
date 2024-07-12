/* COS30008, Lecture 11, 2022
  - Duc Minh Le: adapted from BTree.h in lab 11 to support tree traversal operations
 */

#pragma once

#include <stdexcept>

// Lect 11
#include "queue"
#include "visitors/TreeVisitor.h"

template <typename T>
class BTree
{
private:
  T fKey; // T() for empty BTree
  BTree<T> *fLeft;
  BTree<T> *fRight;

  BTree() : // sentinel constructor
            fKey(T()),
            fLeft(&NIL),
            fRight(&NIL)
  {
  }

  void attach(BTree<T> **aNode, const BTree<T> &aBTree)
  {
    if ((*aNode)->empty())
    {
      *aNode = const_cast<BTree<T> *>(&aBTree);
    }
    else
    {
      throw std::domain_error("Illegal subtree operation.");
    }
  }

  const BTree<T> &detach(BTree<T> **aNode)
  {
    if (!(*aNode)->empty())
    {
      BTree<T> *Result = *aNode; // obtain reference to subtree
      *aNode = &NIL;             // set to NIL
      return *Result;            // return subtree (reference)
    }
    else
    {
      throw std::domain_error("Illegal subtree operation.");
    }
  }

public:
  static BTree<T> NIL; // Empty BTree

  // BTree leaf
  BTree(const T &aKey) : fKey(aKey),
                         fLeft(&NIL),
                         fRight(&NIL)
  {
  }

  // BTree leaf
  BTree(T &&aKey) : fKey(std::move(aKey)),
                    fLeft(&NIL),
                    fRight(&NIL)
  {
  }

  // copy constructor
  BTree(const BTree &aOtherBTree) : BTree()
  {
    *this = aOtherBTree; // use copy assignment
  }

  // move constructor
  BTree(BTree &&aOtherBTree) : BTree()
  {
    *this = std::move(aOtherBTree); // use move assignment
  }

  virtual ~BTree() // destructor
  {
    if (fLeft != &NIL)
    {
      delete fLeft;
    }

    if (fRight != &NIL)
    {
      delete fRight;
    }
  }

  BTree &operator=(const BTree &aOtherBTree) // copy assignment operator
  {
    if (!aOtherBTree.empty())
    {
      if (this != &aOtherBTree)
      {
        fKey = aOtherBTree.fKey;

        if (fLeft != &NIL)
        {
          delete fLeft;
        }

        fLeft = const_cast<BTree<T> &>(aOtherBTree.left()).clone();

        if (fRight != &NIL)
        {
          delete fRight;
        }

        fRight = const_cast<BTree<T> &>(aOtherBTree.right()).clone();
      }

      return *this;
    }
    else
    {
      throw std::domain_error("Illegal binary tree operation.");
    }
  }

  BTree &operator=(BTree &&aOtherBTree) // move assignment operator
  {
    if (!aOtherBTree.empty())
    {
      if (this != &aOtherBTree)
      {
        fKey = std::move(aOtherBTree.fKey);

        if (!aOtherBTree.left().empty())
        {
          fLeft = const_cast<BTree<T> *>(&aOtherBTree.detachLeft());
        }
        else
        {
          fLeft = &NIL;
        }

        if (!aOtherBTree.right().empty())
        {
          fRight = const_cast<BTree<T> *>(&aOtherBTree.detachRight());
        }
        else
        {
          fRight = &NIL;
        }
      }

      return *this;
    }
    else
    {
      throw std::domain_error("Illegal binary tree operation.");
    }
  }

  virtual BTree *clone() // clone a tree
  {
    if (!empty())
    {
      return new BTree(*this); // return new object
    }
    else
    {
      return this; // no clone
    }
  }

  bool empty() const // is tree empty
  {
    return this == &NIL;
  }

  const T &operator*() const // get key (node value)
  {
    return fKey;
  }

  const BTree &left() const
  {
    return *fLeft;
  }

  const BTree &right() const
  {
    return *fRight;
  }

  // tree manipulators
  void attachLeft(const BTree<T> &aBTree)
  {
    attach(&fLeft, aBTree);
  }

  void attachRight(const BTree<T> &aBTree)
  {
    attach(&fRight, aBTree);
  }

  const BTree &detachLeft()
  {
    return detach(&fLeft);
  }

  const BTree &detachRight()
  {
    return detach(&fRight);
  }

  /* Lect 11: depth-first search (recursive): All types of visitors */
  void searchDepthFirst(const TreeVisitor<T>& aVisitor) const {
    if (!empty()) {
      /* pre-order response (only applicable to pre-order traversal):
        visit root (first)
       */
      aVisitor.preVisit(**this); 
      
      // recursive: left subtree
      left().searchDepthFirst(aVisitor);

      /* in-order response (only applicable to in-order traversal):
        visit root (after left subtrees)
       */
      aVisitor.inVisit(**this); 

      // recursive: right subtree
      right().searchDepthFirst(aVisitor);

      /* post-order response  (only applicable to post-order traversal):
        visit root (after right subtrees)
      */
      aVisitor.postVisit(**this); 
    }
  }

  /* alternative: pre-order DFS (stand-alone) */
  void searchDfPre(const TreeVisitor<T>& aVisitor) const {
    if (!empty()) {
      // root first
      aVisitor.visit(**this);

      const BTree<T> * left = &this->left();
      const BTree<T> * right = &this->right();
      left->searchDfPre(aVisitor);
      right->searchDfPre(aVisitor);
    }
  }

  /* alternative: post-order DFS (stand-alone) */
  void searchDfPost(const TreeVisitor<T>& aVisitor) const {
    if (!empty()) {
      const BTree<T> * left = &this->left();
      const BTree<T> * right = &this->right();
      left->searchDfPost(aVisitor);
      right->searchDfPost(aVisitor);
      
      // root last
      aVisitor.visit(**this);
    }
  }

  /* alternative: in-order DFS (stand-alone) */
  void searchDfIn(const TreeVisitor<T>& aVisitor) const {
    if (!empty()) {
      // left
      const BTree<T> * left = &this->left();
      left->searchDfIn(aVisitor);

      // root
      aVisitor.visit(**this);

      // right
      const BTree<T> * right = &this->right();
      right->searchDfIn(aVisitor);
    }
  }

  /* Lect 11: breadth-first search (iterative) */
  void searchBreadthFirst(const TreeVisitor<T>& aVisitor) const {
    if (!empty()) {
      std::queue<const BTree<T>*> lQueue;
      // start with root
      lQueue.push(this);
      while (!lQueue.empty()) {
        // get front element's data
        const BTree<T>* lFront = lQueue.front();  
        if (!lFront->empty()) {
          aVisitor.visit(**lFront);
          lQueue.push(&lFront->left());   // enqueue left subtree
          lQueue.push(&lFront->right());  // enqueue right subtree
        }
        // removes front element
        lQueue.pop(); 
      }
    }
  }

  /* alternative: breadth-first search (recursive) */
  void searchBreadthFirst2(const TreeVisitor<T>& aVisitor) const {
    searchBreadthFirst2(aVisitor, true);
  }

  void searchBreadthFirst2(const TreeVisitor<T>& aVisitor, const bool inclRoot) const {
    if (!empty()) {
      if (inclRoot) {
        // include with root
        aVisitor.visit(**this);
      }
      
      // visit root's children nodes
      if (!left().empty()) aVisitor.visit(*left());
      if (!right().empty()) aVisitor.visit(*right());

      // recursive: next tree level
      left().searchBreadthFirst2(aVisitor, false);
      right().searchBreadthFirst2(aVisitor, false);
    }
  }
};

template <class T>
BTree<T> BTree<T>::NIL;
