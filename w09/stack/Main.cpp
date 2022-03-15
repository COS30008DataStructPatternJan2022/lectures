#include "Stack.h"
#include "iostream"

using namespace std;

int main() {
  Stack<int> lStack(10);

  lStack.push(2);
  lStack.push(34);
  lStack.push(68);

  cout << "Number of elements on the stack: " << lStack.size() << endl;

  // manual pop
  cout << "Top: " << lStack.top() << endl;
  lStack.pop();
  cout << "Top (after pop()): " << lStack.top() << endl;
  lStack.pop();
  lStack.pop();

  // alternative: loop
  /* while (!lStack.isEmpty()) {
    cout << " " << lStack.top();
    lStack.pop();
  }
  cout << endl; */

  //
  cout << "Number of elements on the stack: " << lStack.size() << endl;

  return 0;
}
