#include <vector>
#include <iterator>
#include <iostream>

#include "../../../../utils/functions/Functions.cpp"

using namespace std;
using namespace toolkit;

/* Ref: Lippman et al, Section 10.4 */

/* @effects: result = vector<int> reference */
vector<int> inputStreamIt() {
  cout << "inputStreamIt()" << endl;

  cout << "Enter integers (one by one; end by 'x'):" << endl;
  // input stream iterator bound to cin
  istream_iterator<int> in_iter(cin); // read ints from cin
  istream_iterator<int> eof; // istream ‘‘end’’ iterator
  vector<int> vec(in_iter, eof);
  cout << "Read vector: " << endl;
  printIntVector(vec);

  return vec;

  // longer version
  /* while (in_iter != eof) { // while there’s valid input to read
    // postfix increment reads the stream and returns the old value of the iterator
    // we dereference that iterator to get the previous value read from the stream
    vec.push_back(*in_iter++);
  } */
}

void outputStreamIt() {
  cout << "outputStreamIt()" << endl;
  vector<int> vec = {2, 0, 2, 2, 2022};
  cout << "Vector: " << endl;
  printIntVector(vec);

  // output stream iterator bound to cout
  ostream_iterator<int> out_iter(cout, " ");

  for (auto e : vec) {
    out_iter = e; // the assignment writes this element to cout
  }
  cout << endl;
}

int main() {
  inputStreamIt();

  outputStreamIt();
}