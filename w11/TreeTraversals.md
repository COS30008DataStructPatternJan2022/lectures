Tree traversal logics
--------------------

# Depth-first

```

```
## Pre-order

```
searchDfPre(T: Tree)
  visit(T.root)   // root first
  for each subtree t of T.trees (in sequence)
    dfPreVisit(t)
```
## Post-order

```
searchDfPost(T: Tree)
  for each subtree t of T.trees (in sequence)
    dfPostVisit(t)
  visit(T.root)   // root last
```

## In-order
```
searchDfIn(T: Tree)
  L <- leftSubTrees(T)  // same order as T
  R <- rightSubTrees(T) // same order as T
  for each subtree t in L (in sequence)
    dfInSearch(t)
  visit(T.root)   // root (in-between L, R)
  for each subtree t in R (in sequence)
    dfInSearch(R)
```

# Bread-first

```
searchBf(T: Tree)
  visit(T.root)
  for each subtree t in T (in sequence)
    searchBf(t)
```

# Visitor pattern: Traversal with node processing
```

```



