#include "Stack.h"
#include "iostream"

using namespace std;

int main() {
  Stack<int> lStack(10);

  lStack.push(2);
  lStack.push(34);
  lStack.push(68);

  cout << "Number of elements on the stack: " << lStack.size() << endl;
  cout << "Top: " << lStack.top() << endl;
  lStack.pop();
  cout << "Top (after pop()): " << lStack.top() << endl;
  lStack.pop();
  lStack.pop();
  cout << "Number of elements on the stack (after 2 pop()s): " << lStack.size() << endl;

  return 0;
}
