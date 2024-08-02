#pragma once

template<class T>
class PreOrderVisitor: public TreeVisitor<T> {
public:
  /* override pre-order behaviour */
  virtual void preVisit(const T& aKey) const { 
    this->visit(aKey);
  }  
};