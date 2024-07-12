# include "iostream"

#pragma once

template<class T>
class TreeVisitor {
public:
  /* default deconstructor */
  virtual ~TreeVisitor(){}

  /* default behaviours */
  virtual void preVisit(const T& aKey) const { }

  virtual void postVisit(const T& aKey) const {}

  virtual void inVisit(const T& aKey) const { }

  virtual void visit(const T& aKey) const {
    std::cout << aKey << " ";
  }
};