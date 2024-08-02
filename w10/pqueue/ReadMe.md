`config.h`:
- added a `debug` constant to observe what is going on

`PriorityQueue.h`:
- the implementation uses the built-in `list` library
- includes `config.h` to print debug messages

`Pair.cpp`:
- added overloaded operator `<<` to easily prints Pair (esp. in debug messages)

`Main.cpp`: added two functions for testing
- `queueOfInts()`: to ease testing with int values (e.g. easier to print debug messages)
- `queueOfPairs()`: to test Pair objects. Print actual Pair objects (using `<<` operator) instead of just the values as in the original code