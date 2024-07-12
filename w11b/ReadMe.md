
# Two DFS designs

`Main.cpp` program demonstrates both designs and displays their results in pairs.

## One search function, Multiple Visitors
This is the design provided by the lecture. 

**Advantage**:
- easier for developer because only need to implement one search logic

**Disadvantage**:
- multiple visitor classes are needed 
- client program must know to use **the exact visitor class**
- search behaviour error: accidental (incorrect) implementation of an additional visitor function leads to search error (e.g. pre-order visitor implements `postVisit` function)

## Multiple search functions, One Visitor
This is the alternative design added to `BTree.h`.
Three DFS functions, each of which implements one traversal order:
- `searchDfPre`: pre-order
- `searchDfPost`: post-order
- `searchDfIn`: in order

See [TreeTraversals.md](TreeTraversals.md) for pseudocode of these functions.

**Advantage**: 
- easier for client program to use because only one visitor class is needed

**Disadvantage**: 
- multiple search functions, one for each traversal order

