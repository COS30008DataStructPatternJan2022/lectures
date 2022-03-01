
# R-value references
**Reference**: 
  - Lippman et al, Sect 13.6.1

- rvalue reference is a reference that must be bound to an
rvalue.
- rvalue reference is obtained by using `&&` rather than `&`. 
- rvalue references have the important property that they may be bound only to an object that is about to be destroyed. 
  - we are free to "move" resources from an rvalue reference to another object

# Templates
**Reference**:
- Lippman et al, Chapter 16:
  - function templates: 16.1.1
  - class templates: 16.1.2

# List ADT
- the current design of `SinglyLinkedList` uses `struct`, which exposes the representation (data member visibility = `public`)
- to make it an ADT, replace `struct` by `class` with the data members (`fList`, `fIndex`) being declared as `private`