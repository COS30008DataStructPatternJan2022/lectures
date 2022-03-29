#pragma once

template<class T>
class PostOrderVisitor: public TreeVisitor<T> {
public:
  /* override post-order behaviour */
  virtual void postVisit(const T& aKey) const { 
    this->visit(aKey);
  }  
};