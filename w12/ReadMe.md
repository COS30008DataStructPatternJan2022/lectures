Lecture 12
-------------

# Turing Machine

## Reference 
> [1] J. E. Hopcroft, R. Motwani, and J. D. Ullman, Introduction to Automata Theory, Languages, and Computation, 3rd ed. Boston: Pearson, 2006.
- Section 8.2: Turing Machine
- Section 8.2.2 (formal definition)
- Example 8.2 (state transition table)
- Section 8.2.4: Transition diagram 
- Example 8.3: transition diagram for Example 8.2
> [2] R. Sedgewick and K. Wayne, Algorithms, 4th edition. Upper Saddle River, NJ: Addison-Wesley Professional, 2011.
  - Chapter 6 (Context), pg 910 (Ground work)
  
## Slide 6: Church-Turing Thesis
(Sedgewick & Wayne)
> (Universality of Turing Machine) All physically realizable computing devices can be simulated by a Turing machine
> - a statement about the natural world and cannot be proven (but it can be falsified). 
> - the evidence in favor of the thesis is that mathematicians and computer scientists have developed numerous models of computation, but they all have been proven equivalent to the Turing machine.

> (Computability) There exist problems that cannot be solved by a Turing machine (or by any other computing device, by universality):
> - a mathematical truth
> - the **halting problem** (no program can guarantee to determine whether a given program will halt) is a famous example of nonsolvable/uncomputable problems.

## Slide 8: Formal definition
  - `L`, `R`: move direction left (L) or right (R)
  - accepting states = final states

## Slide 9: addition on Turing Machine

- $Q \setminus \Gamma$: states (1,2,3,4,5,6)
- `" ", "1", "+"`: input symbols in $\Sigma$
- cell values = state transition values, 
- Examples :
  - `1/" ",R` in the cell (`1, " "`) reads as follows:
    - if machine's state is `1` and it reads symbol `" "` then writes symbol `" "`, transitions to state `1` (i.e. stays in this state), and moves `right` (R)
  - `2/"1",R` in the cell (`1, "1"`) reads as follows:
    - if machine's state is `1` and it reads symbol `"1"` then writes symbol `"1"`, transitions to state `2` and moves `right`

## Slide 11: ...No move allowed

State transition table:
- `" "/R/2` reads as follows: writes `" "`, transition to state `2` and moves `right`

## Slide 12: Ackermann function
**Reference**: https://mathworld.wolfram.com/AckermannFunction.html

> - **grows faster than exponential function**, or even a multiple exponential function.
> **Examples**: 
> $$
> A(0,y) = y + 1  \\
> A(1,y) = y + 2 \\
> A(2,y) = 2y + 3 \\
> A(3,y) = 2^{y+3} - 3 \\
> A(4,y) = 2 ^ {2 ^ {...^{2}}} - 3
> $$
> - a simplest example of **well-defined total function**:
>   - **computable but not primitive recursive** (**primitive recursive**: a function that can be implemented using only do-loops)
>   - providing a counterexample to the belief in the early 1900s that every computable function was also primitive recursive

## Slide 13: Halting problem
- See note on Slide 6 above.

# Big-Oh notation
## Reference
> [1] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction to Algorithms, 3rd ed. Cambridge, Mass: The MIT Press, 2009.
>  - Chapter 3

> [2] R. Sedgewick and K. Wayne, Algorithms, 4th edition. Upper Saddle River, NJ: Addison-Wesley Professional, 2011.
>  - Section 1.4: Analysis of algorithm

> [3] A. V. Aho and J. D. Ullman, Foundations of Computer Science: C Edition, 2nd ed. New York: W. H. Freeman, 1994. [Online]. Available: http://infolab.stanford.edu/~ullman/focs.html
>   - Chapter 3 

## Slide 17: running time estimation
- Big-Oh ignores lower-order terms:
  - these terms are insignificant for large input
  - e.g. $f(x) = x^3 + 2x + 1 = O(x^3)$
- Big-Oh does not consider the constant coefficients in higher order terms:
  - these terms are less significant than order of growth for large input
  - e.g. $f(x) = 5x^3 + 2x = O(x^3)$

## Slide 18: performance analysis
**Reference**: 
> [1]T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction to Algorithms, 3rd ed. Cambridge, Mass: The MIT Press, 2009.
  - Section 2.2: Algorithm analysis

### Terms
- **input size**: (most natural measure) the number of items in the input (e.g., the array size n for sorting)
-  **running time**: of an algorithm on a particular input is the number of primitive operations or "steps" executed.
   - **step**: is defined to be machine independent
   - assumes: each step takes a constant amount of time

### Cases of running time
- **best case** (lower bound): shortest running time for all inputs (e.g. when the searched item is the first item)

- **worst case** (upper bound): longest running time for all inputs (e.g. when the searched item is not in the array)

- **average case**: running time for an "average" input -- usually as bad as worst case.
  - See Cormen et al/Chapter 5/Probablistic analysis: average-case running time = average time taken over the distribution of the possible input
    - requires knowledge of the distribution of the inputs
- implies that all inputs of size n are equally likely, which may or
may not be true in a given situation
  - difficult to perform in practice (because lacking knowledge of the input distribution):
    - alternative: randomized algorithm!

## Slide 19: Constant time
- (Sedgewick & Wayne) A program whose running time's order of growth is constant executes a fixed number of operations to finish its job
  - its running time does not depend on input size n

## Slides 36-37: Max subsequence sum
Demonstrate that:
  - different algorithms existing for the same problem
  - these algorithms can (sometimes vastly) differ in performance

Example:  Max subsequence sum
  - `maxSubSumOn3()`: has running time of $O(n^3)$
    - considers a larger set of subsequences, that contain elements that are not necessarily consecutive
  - `maxSubSumOn()`: has running time of $O(n)$
    - only considers subsequences of consecutive elements (starting from the first element)

# Algorithmic Patterns
**Reference**: 
> https://cs.lmu.edu/~ray/classes/a/
  - Algorithm patterns and the strategies

## direct strategies

### Brute force
- Enumerate all possible solutions and try them all until you find a solution. 
  - Not really a “pattern”:" could in theory do all algorithms in this way, but don’t.
- Slide 41: Bubble Sort
  - `swap(j+1, j` should be `swap(aArray, j+1, j`

### Greedy 
- Perform the "best looking" thing at each step. 
  - may miss a solution, or may miss the optimal one. 
  - in some cases where it is known to work, it is a great approach.

Examples:
  - Minimum Spanning Trees
  - Naive coin changing
  - Huffman Compression
  - Dijkstra’s Shortest Path 

- Knapsack algorithms: https://en.wikipedia.org/wiki/Knapsack_problem
- Sudoku Solver: https://en.wikipedia.org/wiki/Sudoku_solving_algorithms
  - different algorithms exist for solving sudoku (backtracking,  Stochastic search / optimization methods, Constraint programming, Exact cover, Relations and residuals)
  - hard sudoku: https://sudoku.com/hard/
  
## backtracking strategies
- systematically generating possible solutions to a problem in which you sometimes have to back up when realizing your paritally generated candidate can’t possibly be extended to a real solution

Examples: 
- Map coloring
- Eight queens
- Knight’s Tour
- Maze solving
- Regular expression matching
- Generic path finding

## top-down (divide & conquer) strategies
- Breaking down a problem into multiple independent subproblems, solving the subproblems (recursively), and combining those solutions into a solution for the original problem.

Examples:
  - Mergesort
  - Quicksort
  - Median
  - Karatsuba’s Integer Multiplication
  - Matrix Multiplication
  - FFT
  - Nearest Neighbors

## dynamic programming
- Dynamic programming: solving an optimization problem by breaking down a problem into multiple overlapping subproblems
  - solving the subproblems (recursively), and 
  - combining those solutions into a solution for the original problem.
  - idea is to cache the results of overlapping subproblems
  - can be done bottom up (table construction) or top-down (recursive with memoization)

Examples:
- Interval scheduling
- Longest common subsequence
- Coin changing
- Levenshtein distance
- Matrix-chain multiplication
- Integer knapsack
- Shortest path
- Word wrap
- Traveling salesperson

## bottom-up strategies
- a strategy for dynamic programming

## randomized strategies

- (Cormen et al.) **randomized algorithm** = an algorithm, the behaviour of one of whose parts is made random by a probability and randomness technique
  - i.e. behaviour is determined not only by an input but also by values produced by a random-number generator
  - running time of this algo is called **expected running time**
- Used when it is difficult, if not impossible, to determine the distribution of the inputs (used in average case analysis)

