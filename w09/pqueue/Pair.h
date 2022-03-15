#include <iostream>

/**
 * @brief Represents a comparable (key,value) pair. Pairs are comparable by their keys. This is supported by the operator '<' and is used by sorted containers (e.g. priority queue) to sort the pairs.
 * 
 * @tparam K key
 * @tparam V value
 */
template<class K, class V>
struct Pair {
  K key;
  V value;

  Pair(const K& aKey, const V& aValue) : key(aKey), value(aValue) {}

  bool operator< (const Pair<K,V>& aOther) const {
    return key < aOther.key;
  }

  bool operator== (const Pair<K,V>& aOther) const {
    return key == aOther.key && value == aOther.value;
  }

  string to_string() const {
    return value;
  }

  // output an item to the output stream
  friend ostream& operator<<( ostream& aOStream, const Pair& p) {
    using namespace std;
      aOStream << "Pair(" << p.key <<  "," 
               << p.value << ")";
      return aOStream;
  }
};