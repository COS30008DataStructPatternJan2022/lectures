
# References
- Cormen et al:
  - Section 10.4: Rooted tree

# Slide notes
1. `NTree.h`:
   - slides do not provide implementation for some operations
   - need to adapt code from `BTree.h` in Lab 11.
  
2. `BTree`: why should we not create it from a specialised template of `NTree`?
   - because `BTree`'s concept specifically requires left and right subtrees, which are not supported in the definition of `NTree<T,2>`