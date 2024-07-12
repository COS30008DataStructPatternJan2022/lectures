#include "BinarySearchTree.h"
#include "../visitors/PreOrderVisitor.h"
#include "iostream"

using namespace std;

void testVisitor() {
  BinarySearchTree<int> lTree;

  int keys[] = {25,10,15,37,30,65};
  cout << "keys: "; 
  for (int& key: keys) {
    cout << key << " ";
    lTree.insert(key);
  }
  cout << endl;

  cout << "traverseDepthFirst(): ";
  lTree.traverseDepthFirst(PreOrderVisitor<int>());
  cout << endl;

  cout << "insert(8): ";
  cout << lTree.insert(8);
  cout << endl;

  cout << "traverseDepthFirst(): ";
  lTree.traverseDepthFirst(PreOrderVisitor<int>());
  cout << endl;

  cout << "remove(25): ";
  cout << lTree.remove(25);
  cout << endl;

  cout << "traverseDepthFirst(): ";
  lTree.traverseDepthFirst(PreOrderVisitor<int>());
  cout << endl;

}

int main() {
  testVisitor();

  return 0;
}