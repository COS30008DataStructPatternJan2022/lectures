#include "Queue.h"
#include "iostream"

using namespace std;

int main() {
  Queue<int> lQueue;

  lQueue.enqueue(20);
  lQueue.enqueue(3);
  lQueue.enqueue(37);

  cout << "Number of elements in the queue: " << lQueue.size() << endl;

  /* manual dequeue */
  cout << "Top: " << lQueue.top() << endl; 
  lQueue.dequeue();
  cout << "Top: " << lQueue.top() << endl; 
  lQueue.dequeue();
  cout << "Top: " << lQueue.top() << endl; 
  lQueue.dequeue();

  /* alternative: loop  */
  while (!lQueue.isEmpty()) {
    cout << " " << lQueue.top();
    lQueue.dequeue();
  }
  cout << endl;
  
  cout << "Number of elements in the queue: " << lQueue.size() << endl;

  return 0;
}
