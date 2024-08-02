Week 09 - Container Types
------------------------

Two container types: Stack and Queue. 

C++ provides built-in types for `stack` and `queue`. These are called **container adapters** as they use another container type to hold their elements.

Lecture slides discuss custom designs of stack and queue. 

# References
- Lippman et all
  - Chapter 9 (Sequential Containers):
    - Section 9.6: Container adapters (stack, queue)
- Other references
  - Stack: http://www.cplusplus.com/reference/stack/stack/
    - suitable underlying container types: deque, vector
  - Queue: http://www.cplusplus.com/reference/queue/queue/ 
    - suitable underlying container types: deque, list

# Stack
## Reverse Polish Notation (RPN)

## Design
The lecture discusses 2 designs:
1. **fixed-size stack** (main focus), which uses array as the underlying container type.
   - `Stack.fStackPointer`: location of the **next** pushed element. It is updated after each push.
2. **dynamically sized stack**: uses list as the underlying container type

# Queue

## Design
Lecture discusses 2 designs:
1. **dynamically sized queue**: uses list as the underlying container type
2. **priority queue**