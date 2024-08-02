#include "PriorityQueue.h"
#include "Pair.h"
#include <iostream>

using namespace std;

void queueOfInts() {
  PriorityQueue<int> queue;
  queue.enqueue(20);
  queue.enqueue(30);
  queue.enqueue(29);
  queue.enqueue(15);
  queue.enqueue(45);
  queue.enqueue(25);

  cout << "Number of elements in the queue: " << queue.size() << endl;
  cout << "Top: " << queue.top() << endl; 
  queue.dequeue();
  cout << "Top: " << queue.top() << endl; 
  queue.dequeue();
  cout << "Top: " << queue.top() << endl; 
  queue.dequeue();
  
  cout << "Number of elements in the queue: " << queue.size() << endl;

}

void queueOfPairs() {
  PriorityQueue< Pair<int,int> > lQueue;
  lQueue.enqueue(Pair<int,int>(4,20));
  lQueue.enqueue(Pair<int,int>(5,30));
  lQueue.enqueue(Pair<int,int>(5,25));
  lQueue.enqueue(Pair<int,int>(4,29));
  lQueue.enqueue(Pair<int,int>(6,15));
  lQueue.enqueue(Pair<int,int>(3,45));

  cout << "Number of elements in the queue: " << lQueue.size() << endl;
  cout << "Top: " << lQueue.top() << endl; 
  lQueue.dequeue();
  cout << "Top: " << lQueue.top() << endl; 
  lQueue.dequeue();
  cout << "Top: " << lQueue.top() << endl; 
  lQueue.dequeue();
  
  cout << "Number of elements in the queue: " << lQueue.size() << endl;
}

int main() {
  
  cout << "*** queueOfInts() ***" << endl;
  queueOfInts();

  cout << endl << "*** queueOfPairs() ***" << endl;
  queueOfPairs();

  return 0;
}
