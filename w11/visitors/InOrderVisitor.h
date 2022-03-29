#pragma once

template<class T>
class InOrderVisitor: public TreeVisitor<T> {
public:
  /* override in-order behaviour */
  virtual void inVisit(const T& aKey) const { 
    this->visit(aKey);
  }  
};