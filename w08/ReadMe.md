# References
- C++ exceptions: https://en.cppreference.com/w/cpp/error/exception
- Lippman et al:
  - 6.1.1: Local static objects
  - 7.6: Static class members (data member and function)
  - 19.1: Controlling memory allocation
  - 12: Dynamic memory
  - 13: Copy control

# Object life time
(Lipman, Chapter 6)

Every object has an associated lifetime.
- **Nonstatic objects** that are defined inside a block exist from when their definition is encountered until the end of the block in which they are defined. 
- **Global objects**: created during program startup.
- **Local static objects**: created before the first time execution passes through the object’s definition. 
- **Global objects**, **local static objects**: are destroyed when the `main` function ends.

# Program memory
(Lipman, Chapter 12)
- **static memory**: static objects & vars defined outside of any function
- **stack memory**: nonstatic objects inside a function
- **heap memory** (a.k.a free store): objects that program dynamically allocates at run-time.
  - e.g. when using the `new` keyword to create an object
  - program must control dynamic objects (to destroy them when they are not used)
  - easier said than done! (helped in C++11 by smart pointers)

## C++ call stack explanation

- Video 1: https://youtu.be/uG_JOJgwbco
  Visual explanation of:
   - call stack, frames, heap, automatic and dynamic objects/variables
   - the `new`, `delete` keywords
- Explanation: https://people.cs.rutgers.edu/~pxk/419/notes/frames.html
- Video 2: https://youtu.be/aCPkszeKRa4
  - visual explanation of call stack, using recursion to illustrate

## Note
- The main code examples are provided as part of `lab09`