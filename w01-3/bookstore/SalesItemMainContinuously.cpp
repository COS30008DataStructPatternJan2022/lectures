#include "iostream"
#include "SalesItem.h"

using namespace std;

int main() {
  SalesItem lTotal, lCurrent;
  // continuously create new SalesItem and group ones that have the same ISBN
  cout << "Enter SalesItem continuously:" << endl;
  if (cin >> lTotal) {
    while (cin >> lCurrent) {
      if (lTotal.hasSameISBN(lCurrent)) {
        lTotal += lCurrent;
      } else {
        cout << lTotal << endl;
        lTotal = lCurrent;
      }
      cout << lTotal << endl;
    }
  } else {
    cerr << "Error, no data!" << endl;
    return -1;
  }

  return 0;
}