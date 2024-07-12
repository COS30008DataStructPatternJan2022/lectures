/* Tree: design specification */
#include "iostream"

template<typename T, size_t N>
class NTree {
private:
  /* payload or data that a tree node carries. 
  Use T() for empty NTree */
  T fKey;
  /* array of N subtrees of degree N */
  NTree<T,N>* fNodes[N];

  // sentinel constructor: internal use only
  NTree();

public: 
  /* empty tree */
  static NTree<T,N> NIL;
  
  /* constructor: NTree leaf */
  NTree(const T& aKey);
  /* constructor: NTree leaf */
  NTree(T&& aKey);

  /* copy constructor */
  NTree(const NTree& aOtherNTree);

  /* move constructor */
  NTree (NTree&& aOtherNTree);

  /* deconstructor */
  virtual ~NTree();

  // OPERATIONS

  /*  copy assignment */
  NTree& operator=( const NTree& aOtherNTree);
  /* move assignment */
  NTree& operator=( NTree&& aOtherNTree);
  /* clone a tree */
  virtual NTree* clone();

  /* is this empty? */
  bool empty() const; 

  /* get key (node value) */
  const T& operator*() const;

  /* indexer */
  const NTree& operator[] (size_t aIndex) const;

  /* tree manipulators */
  /* attach a subtree */
  void attach(size_t aIndex, const NTree<T,N>& aNTree);
  /* detach (remove) a subtree */
  const NTree& detach(size_t aIndex);
};