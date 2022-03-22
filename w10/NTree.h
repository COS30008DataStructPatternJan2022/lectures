/* Tree: implementation */
#include "iostream"

template<typename T, size_t N>
class NTree {
private:
  /* Root of the tree (a.k.a payload/value)
  Note: use T() for empty NTree */
  T fKey;
  /* array of N subtrees of degree N */
  NTree<T,N>* fNodes[N];

  // sentinel constructor: internal use only
  NTree(): fKey(T()) {
    for (size_t i = 0; i < N; i++) {
      fNodes[i] = &NIL;
    }
  }

public: 
  /* empty tree */
  static NTree<T,N> NIL;
  /* constructor: NTree leaf */
  NTree(const T& aKey): fKey(aKey) {
    for (size_t i = 0; i < N; i++) {
      fNodes[i] = &NIL;
    }
  }
  
  /* constructor: NTree leaf */
  NTree(T&& aKey): fKey(std::move(aKey)) {
    for (size_t i = 0; i < N; i++) {
      fNodes[i] = &NIL;
    }
  }

  /* copy constructor */
  NTree(const NTree& aOtherNTree) {
    *this = aOtherNTree;
  }

  /* move constructor */
  NTree (NTree&& aOtherNTree) {
    *this = std::move(aOtherNTree);
  }

  /* deconstructor */
  virtual ~NTree() {
    for (size_t i = 0; i < N; i++) {
      if ( fNodes[i] != &NIL) {  // dont delete NIL
        // ERROR: run-time error ("double free or corruption (out)") if do not detach all nodes before this deconstructor is called!
        delete fNodes[i];
      }
    }
  }

  // OPERATIONS

  /*  copy assignment */
  NTree& operator=( const NTree& aOtherNTree) {
    if (!aOtherNTree.empty()) {
      if (this != &aOtherNTree) {
        // the root
        fKey = aOtherNTree.fKey;
        // the subtrees
        for (size_t i = 0; i < N; i++) {
          if (!aOtherNTree[i].empty()) {  // assign as new to clone
            delete fNodes[i]; // delete existing 
            fNodes[i] = const_cast<NTree<T,N>&>(aOtherNTree[i]).clone();
          } else {
            fNodes[i] = &NIL;
          }
        }
      }
      return *this;
    } else {
      throw std::domain_error("Illegal tree operation: target tree is empty");
    }    
  }

  /* move assignment */
  NTree& operator=( NTree&& aOtherNTree) {
    if (!aOtherNTree.empty()) {
      if (this != &aOtherNTree) {
        // the root
        fKey = std::move(aOtherNTree.fKey);
        // the subtrees
        for (size_t i = 0; i < N; i++) {
          if (!aOtherNTree[i].empty()) {
            delete fNodes[i]; // delete existing 
            fNodes[i] = const_cast<NTree<T,N>*>(&aOtherNTree.detach(i));
          } else {
            fNodes[i] = &NIL;
          }
        }
      }
      return *this;
    } else {
      throw std::domain_error("Illegal tree operation: target tree is empty");
    }
  }


  /* clone a tree */
  virtual NTree* clone() {
    // throw std::domain_error("Not Yet Implemented!");
    if (!empty()){
      return new NTree(*this);              // return new object
    } else {
      return this;                            // no clone
    }
  }

  /* is this empty? */
  bool empty() const {
    return this == &NIL;
  }

  /* get key (node value) */
  const T& operator*() const {
    return fKey;
  }

  /* indexer */
  const NTree& operator[] (size_t aIndex) const {
    if (!empty()) {
      if (aIndex < N) {
        // returns reference to subtree (instead of pointer)
        // to prevent accidental modifications
        return *fNodes[aIndex];
      } else {
        throw std::out_of_range("Illegal subtree index!");
      }
    } else {
      throw std::domain_error("Empty tree!");
    }
  }

  /* tree manipulators */
  /* attach a subtree */
  void attach(size_t aIndex, const NTree<T,N>& aNTree) {
    if (!empty()) {
      if (aIndex < N) {
        if (fNodes[aIndex]->empty()) {
          fNodes[aIndex] = const_cast<NTree<T,N>*>(&aNTree);
        } else {
          throw std::domain_error("Non-empty subtree present!");
        }
      } else {
        throw std::out_of_range("Illegal subtree index!");
      }
    } else {
      throw std::domain_error("Empty tree!");
    }
  }

  /* detach a subtree */
  const NTree& detach(size_t aIndex) {
    if (!empty()) {
      if (aIndex < N && !fNodes[aIndex]->empty()) {
        // reference to subtree
        const NTree<T,N>& result = *fNodes[aIndex];
        // set it to NIL
        fNodes[aIndex] = &NIL;
        // return the reference
        return result;
      } else {
        throw std::out_of_range("Illegal subtree index!");
      }
    } else {
      throw std::domain_error("Empty tree!");
    }
  }
};

// initialise static variable NIL using private default constructor
template<class T, size_t N>
NTree<T,N> NTree<T,N>::NIL;